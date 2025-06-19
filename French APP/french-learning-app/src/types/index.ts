// Core TypeScript interfaces following the development rules

export interface User {
	id: string;
	username: string;
	email: string;
	level: "beginner" | "intermediate" | "advanced";
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
	created_at: string;
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

export interface Lesson {
	id: number;
	module_id: number;
	title: string;
	content: any; // JSONB content
	lesson_type: LessonType;
	order_index: number;
	is_active: boolean;
}

export enum LessonType {
	VOCABULARY = "vocabulary",
	GRAMMAR = "grammar",
	PRONUNCIATION = "pronunciation",
	CONVERSATION = "conversation",
}

export interface Vocabulary {
	id: number;
	french_word: string;
	english_translation: string;
	pronunciation?: string;
	audio_url?: string;
	example_sentence_fr?: string;
	example_sentence_en?: string;
	difficulty_level: string;
	category: string;
}

export interface UserProgress {
	id: number;
	user_id: string;
	lesson_id: number;
	completed_at?: string;
	score: number;
	time_spent: number; // in seconds
}

export interface AuthContextType {
	user: User | null;
	loading: boolean;
	signIn: (email: string, password: string) => Promise<void>;
	signOut: () => Promise<void>;
	signUp: (email: string, password: string, userData: any) => Promise<void>;
	setUser: (user: User | null) => void;
}

export interface ApiResponse<T> {
	data: T | null;
	error: string | null;
	success: boolean;
}
