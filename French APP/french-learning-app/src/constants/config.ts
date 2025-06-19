// Environment configuration
// This file should be copied to .env and filled with actual values

// Supabase Configuration
export const supabaseConfig = {
	url: process.env.EXPO_PUBLIC_SUPABASE_URL || "YOUR_SUPABASE_URL",
	anonKey:
		process.env.EXPO_PUBLIC_SUPABASE_ANON_KEY || "YOUR_SUPABASE_ANON_KEY",
};

// App Configuration
export const appConfig = {
	name: "FrenchMaster",
	version: "1.0.0",
	stage: "development",
};

// Feature Flags
export const features = {
	speechRecognition: false, // Will be enabled in Stage 5
	aiIntegration: false, // Will be enabled in Stage 6
	offlineMode: false, // Will be enabled in Stage 7
};
