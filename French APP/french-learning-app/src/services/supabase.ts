import { createClient } from "@supabase/supabase-js";
import { supabaseConfig } from "../constants/config";

export const supabase = createClient(
	supabaseConfig.url,
	supabaseConfig.anonKey
);

// Configuration options
export const supabaseClientConfig = {
	auth: {
		storage: null, // Will use AsyncStorage when properly configured
		autoRefreshToken: true,
		persistSession: true,
		detectSessionInUrl: false,
	},
};
