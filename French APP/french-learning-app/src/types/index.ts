// Core TypeScript interfaces following the development rules

export type UserLevel = "beginner" | "intermediate" | "advanced";

export interface User {
	id: string;
	username: string;
	email: string;
	level: UserLevel;
	points: number;
	streakDays: number;
	createdAt: string;
}

export interface UserProfile {
	id: string;
	username?: string;
	full_name?: string;
	avatar_url?: string;
	level: string;
	points: number;
	streak_days: number;
	// Stage 2 additions
	last_login_at?: string;
	total_lessons_completed: number;
	total_time_spent: number; // in minutes
	favorite_topic?: string;
	daily_goal: number; // minutes per day
	notification_enabled: boolean;
	created_at: string;
	updated_at: string;
}

export interface UserSession {
	id: string;
	user_id: string;
	started_at: string;
	ended_at?: string;
	duration_minutes: number;
	lessons_completed: number;
	points_earned: number;
	created_at: string;
}

export interface DailyStreak {
	id: string;
	user_id: string;
	streak_date: string;
	minutes_studied: number;
	lessons_completed: number;
	points_earned: number;
	created_at: string;
}

export interface Achievement {
	id: string;
	name: string;
	description?: string;
	icon?: string;
	badge_color: string;
	points_required: number;
	type: 'general' | 'streak' | 'lessons' | 'time';
	is_active: boolean;
	created_at: string;
}

export interface UserAchievement {
	id: string;
	user_id: string;
	achievement_id: string;
	earned_at: string;
	achievement?: Achievement;
}

export interface Level {
	id: number;
	name: string;
	description: string;
	order_index: number;
	is_active: boolean;
}

export interface Module {
	id: number;
	level_id: number;
	title: string;
	description: string;
	order_index: number;
	is_active: boolean;
}

export type LessonType = "vocabulary" | "grammar" | "conversation" | "pronunciation" | "cultural";

export interface Lesson {
	id: number;
	module_id: number;
	title: string;
	content: any; // JSONB content
	lesson_type: LessonType;
	order_index: number;
	is_active: boolean;
}

export interface Vocabulary {
	id: number;
	level_id: number;
	french_word: string;
	english_translation: string;
	pronunciation: string;
	example_sentence_french: string;
	example_sentence_english: string;
	category: string;
	difficulty_level: number;
	is_active: boolean;
}

export interface GrammarRule {
	id: number;
	level_id: number;
	title: string;
	explanation: string;
	examples: any; // JSONB
	difficulty_level: string;
	is_active: boolean;
}

export interface Question {
	id: number;
	lesson_id?: number;
	vocabulary_id?: number;
	grammar_rule_id?: number;
	question_text: string;
	question_type: string;
	options: any; // JSONB
	correct_answer: string;
	explanation?: string;
	points: number;
	difficulty_level: number;
	is_active: boolean;
}

export interface UserProgress {
	id: number;
	user_id: string;
	lesson_id: number;
	completed_at?: string;
	score?: number;
	time_spent: number; // in seconds
	attempts: number;
}

export interface UserVocabularyProgress {
	id: number;
	user_id: string;
	vocabulary_id: number;
	mastery_level: number; // 1-5 scale
	last_reviewed?: string;
	next_review?: string;
	total_attempts: number;
	correct_attempts: number;
}

// API Response wrapper
export interface ApiResponse<T> {
	data: T | null;
	error: string | null;
	success: boolean;
}

// Authentication context types
export interface AuthContextType {
	user: User | null;
	loading: boolean;
	signUp: (email: string, password: string, userData: Partial<UserProfile>) => Promise<void>;
	signIn: (email: string, password: string) => Promise<void>;
	signOut: () => Promise<void>;
	setUser: (user: User | null) => void;
}
