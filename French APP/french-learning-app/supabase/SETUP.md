# Supabase Project Setup Instructions

## Step 1: Get Your Project Credentials

1. Go to your Supabase Dashboard: https://supabase.com/dashboard
2. Select your "French Learning App" project (ozcdaztxzadwdytuzfay)
3. Go to Settings → API
4. Copy the following values:

### Required Credentials:

- **Project URL**: `https://ozcdaztxzadwdytuzfay.supabase.co`
- **Anon/Public Key**: (Copy from API settings)

## Step 2: Create Environment File

1. Copy `.env.example` to `.env`:

```bash
copy .env.example .env
```

2. Edit `.env` file with your credentials:

```env
EXPO_PUBLIC_SUPABASE_URL=https://ozcdaztxzadwdytuzfay.supabase.co
EXPO_PUBLIC_SUPABASE_ANON_KEY=YOUR_ANON_KEY_HERE
EXPO_PUBLIC_APP_ENV=development
```

## Step 3: Set up Database Schema

In your Supabase Dashboard → SQL Editor, run this SQL:

```sql
-- Users table (extends Supabase auth.users)
CREATE TABLE IF NOT EXISTS profiles (
  id UUID REFERENCES auth.users ON DELETE CASCADE PRIMARY KEY,
  username TEXT UNIQUE,
  full_name TEXT,
  avatar_url TEXT,
  level TEXT DEFAULT 'beginner',
  points INTEGER DEFAULT 0,
  streak_days INTEGER DEFAULT 0,
  created_at TIMESTAMP WITH TIME ZONE DEFAULT NOW(),
  updated_at TIMESTAMP WITH TIME ZONE DEFAULT NOW()
);

-- Enable RLS (Row Level Security)
ALTER TABLE profiles ENABLE ROW LEVEL SECURITY;

-- Create policies
CREATE POLICY "Public profiles are viewable by everyone"
ON profiles FOR SELECT
USING (true);

CREATE POLICY "Users can insert their own profile"
ON profiles FOR INSERT
WITH CHECK (auth.uid() = id);

CREATE POLICY "Users can update their own profile"
ON profiles FOR UPDATE
USING (auth.uid() = id);

-- Create updated_at trigger function
CREATE OR REPLACE FUNCTION update_updated_at_column()
RETURNS TRIGGER AS $$
BEGIN
  NEW.updated_at = NOW();
  RETURN NEW;
END;
$$ language 'plpgsql';

-- Create trigger for profiles table
CREATE TRIGGER update_profiles_updated_at
  BEFORE UPDATE ON profiles
  FOR EACH ROW EXECUTE FUNCTION update_updated_at_column();

-- Create function to handle new user registration
CREATE OR REPLACE FUNCTION public.handle_new_user()
RETURNS TRIGGER AS $$
BEGIN
  INSERT INTO public.profiles (id, full_name, avatar_url, username)
  VALUES (
    new.id,
    new.raw_user_meta_data->>'full_name',
    new.raw_user_meta_data->>'avatar_url',
    new.raw_user_meta_data->>'username'
  );
  RETURN new;
END;
$$ language plpgsql security definer;

-- Create trigger for new user registration
CREATE OR REPLACE TRIGGER on_auth_user_created
  AFTER INSERT ON auth.users
  FOR EACH ROW EXECUTE FUNCTION public.handle_new_user();
```

## Step 4: Verify Setup

1. Start your app: `npm start`
2. Test user registration
3. Check if profiles are created in Supabase Dashboard → Table Editor → profiles

## Step 5: Optional - Local Development Setup

If you want to use local Supabase development (requires Docker):

1. Install Docker Desktop
2. Start Docker
3. Run: `supabase start`
4. Use local URLs for development

---

**Once you complete these steps, your authentication system will be fully functional!**
