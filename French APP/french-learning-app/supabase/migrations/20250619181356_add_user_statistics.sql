-- Stage 2: Enhanced User Statistics and Profile Management
-- Add additional profile fields and create related tables

-- Extend profiles table with more fields
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS last_login_at TIMESTAMP WITH TIME ZONE;
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS total_lessons_completed INTEGER DEFAULT 0;
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS total_time_spent INTEGER DEFAULT 0; -- in minutes
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS favorite_topic TEXT;
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS daily_goal INTEGER DEFAULT 15; -- minutes per day
ALTER TABLE profiles ADD COLUMN IF NOT EXISTS notification_enabled BOOLEAN DEFAULT true;

-- Create user sessions table for tracking learning sessions
CREATE TABLE IF NOT EXISTS user_sessions (
  id UUID DEFAULT gen_random_uuid() PRIMARY KEY,
  user_id UUID REFERENCES auth.users ON DELETE CASCADE NOT NULL,
  started_at TIMESTAMP WITH TIME ZONE DEFAULT NOW(),
  ended_at TIMESTAMP WITH TIME ZONE,
  duration_minutes INTEGER DEFAULT 0,
  lessons_completed INTEGER DEFAULT 0,
  points_earned INTEGER DEFAULT 0,
  created_at TIMESTAMP WITH TIME ZONE DEFAULT NOW()
);

-- Create daily streaks tracking table
CREATE TABLE IF NOT EXISTS daily_streaks (
  id UUID DEFAULT gen_random_uuid() PRIMARY KEY,
  user_id UUID REFERENCES auth.users ON DELETE CASCADE NOT NULL,
  streak_date DATE NOT NULL,
  minutes_studied INTEGER DEFAULT 0,
  lessons_completed INTEGER DEFAULT 0,
  points_earned INTEGER DEFAULT 0,
  created_at TIMESTAMP WITH TIME ZONE DEFAULT NOW(),
  UNIQUE(user_id, streak_date)
);

-- Create achievements table
CREATE TABLE IF NOT EXISTS achievements (
  id UUID DEFAULT gen_random_uuid() PRIMARY KEY,
  name TEXT NOT NULL,
  description TEXT,
  icon TEXT,
  badge_color TEXT DEFAULT '#FFD700',
  points_required INTEGER DEFAULT 0,
  type TEXT DEFAULT 'general', -- 'general', 'streak', 'lessons', 'time'
  is_active BOOLEAN DEFAULT true,
  created_at TIMESTAMP WITH TIME ZONE DEFAULT NOW()
);

-- Create user achievements junction table
CREATE TABLE IF NOT EXISTS user_achievements (
  id UUID DEFAULT gen_random_uuid() PRIMARY KEY,
  user_id UUID REFERENCES auth.users ON DELETE CASCADE NOT NULL,
  achievement_id UUID REFERENCES achievements ON DELETE CASCADE NOT NULL,
  earned_at TIMESTAMP WITH TIME ZONE DEFAULT NOW(),
  UNIQUE(user_id, achievement_id)
);

-- Enable RLS on new tables
ALTER TABLE user_sessions ENABLE ROW LEVEL SECURITY;
ALTER TABLE daily_streaks ENABLE ROW LEVEL SECURITY;
ALTER TABLE achievements ENABLE ROW LEVEL SECURITY;
ALTER TABLE user_achievements ENABLE ROW LEVEL SECURITY;

-- Create policies for user_sessions
CREATE POLICY "Users can view their own sessions" 
ON user_sessions FOR SELECT 
USING (auth.uid() = user_id);

CREATE POLICY "Users can insert their own sessions" 
ON user_sessions FOR INSERT 
WITH CHECK (auth.uid() = user_id);

CREATE POLICY "Users can update their own sessions" 
ON user_sessions FOR UPDATE 
USING (auth.uid() = user_id);

-- Create policies for daily_streaks
CREATE POLICY "Users can view their own streaks" 
ON daily_streaks FOR SELECT 
USING (auth.uid() = user_id);

CREATE POLICY "Users can insert their own streaks" 
ON daily_streaks FOR INSERT 
WITH CHECK (auth.uid() = user_id);

CREATE POLICY "Users can update their own streaks" 
ON daily_streaks FOR UPDATE 
USING (auth.uid() = user_id);

-- Create policies for achievements (public read)
CREATE POLICY "Achievements are viewable by everyone" 
ON achievements FOR SELECT 
USING (true);

-- Create policies for user_achievements
CREATE POLICY "Users can view their own achievements" 
ON user_achievements FOR SELECT 
USING (auth.uid() = user_id);

CREATE POLICY "Users can earn achievements" 
ON user_achievements FOR INSERT 
WITH CHECK (auth.uid() = user_id);

-- Insert some default achievements
INSERT INTO achievements (name, description, icon, badge_color, points_required, type) VALUES
('Welcome!', 'Created your first profile', '🎉', '#4CAF50', 0, 'general'),
('First Steps', 'Completed your first lesson', '👶', '#2196F3', 10, 'lessons'),
('Getting Started', 'Earned your first 50 points', '⭐', '#FF9800', 50, 'general'),
('Consistent Learner', 'Maintained a 3-day streak', '🔥', '#F44336', 0, 'streak'),
('Dedicated Student', 'Maintained a 7-day streak', '🏆', '#9C27B0', 0, 'streak'),
('French Enthusiast', 'Earned 500 points', '🇫🇷', '#FFD700', 500, 'general'),
('Study Master', 'Studied for 60 minutes total', '📚', '#607D8B', 0, 'time');

-- Create function to update user stats
CREATE OR REPLACE FUNCTION update_user_stats()
RETURNS TRIGGER AS $$
BEGIN
  -- Update last_login_at when user signs in
  IF TG_TABLE_NAME = 'profiles' THEN
    NEW.updated_at = NOW();
  END IF;
  RETURN NEW;
END;
$$ language plpgsql security definer;

-- Create function to calculate and update streak
CREATE OR REPLACE FUNCTION update_daily_streak(p_user_id UUID, p_minutes INTEGER DEFAULT 0, p_lessons INTEGER DEFAULT 0, p_points INTEGER DEFAULT 0)
RETURNS VOID AS $$
BEGIN
  INSERT INTO daily_streaks (user_id, streak_date, minutes_studied, lessons_completed, points_earned)
  VALUES (p_user_id, CURRENT_DATE, p_minutes, p_lessons, p_points)
  ON CONFLICT (user_id, streak_date)
  DO UPDATE SET
    minutes_studied = daily_streaks.minutes_studied + p_minutes,
    lessons_completed = daily_streaks.lessons_completed + p_lessons,
    points_earned = daily_streaks.points_earned + p_points;

  -- Update user's streak count in profiles
  WITH streak_count AS (
    SELECT COUNT(*) as days
    FROM daily_streaks 
    WHERE user_id = p_user_id 
    AND streak_date >= CURRENT_DATE - INTERVAL '30 days'
    AND streak_date <= CURRENT_DATE
    ORDER BY streak_date DESC
  )
  UPDATE profiles 
  SET streak_days = (SELECT days FROM streak_count)
  WHERE id = p_user_id;
END;
$$ language plpgsql security definer;
