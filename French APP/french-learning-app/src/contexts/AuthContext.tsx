import React, {
	createContext,
	useContext,
	useEffect,
	useState,
	ReactNode,
} from "react";
import { AuthContextType, User } from "../types";
import { SupabaseService } from "../services/supabaseService";
import { supabase } from "../services/supabase";

const AuthContext = createContext<AuthContextType | undefined>(undefined);

interface AuthProviderProps {
	children: ReactNode;
}

export const AuthProvider: React.FC<AuthProviderProps> = ({ children }) => {
	const [user, setUser] = useState<User | null>(null);
	const [loading, setLoading] = useState(true);

	useEffect(() => {
		// Check for existing session on app start
		checkUserSession();
		// Listen for auth state changes
		const {
			data: { subscription },
		} = supabase.auth.onAuthStateChange(async (event, session) => {
			try {
				if (session?.user) {
					const userResult = await SupabaseService.getCurrentUser();
					if (userResult.success && userResult.data) {
						setUser(userResult.data);
					}
				} else {
					setUser(null);
				}
				setLoading(false);
			} catch (error) {
				const errorMessage =
					error instanceof Error ? error.message : String(error);
				if (!errorMessage.includes("Auth session missing")) {
					console.error("Error in auth state change:", error);
				}
				setUser(null);
				setLoading(false);
			}
		});

		return subscription?.unsubscribe;
	}, []);
	const checkUserSession = async () => {
		try {
			const userResult = await SupabaseService.getCurrentUser();
			if (userResult.success && userResult.data) {
				setUser(userResult.data);
			} else {
				// No session exists, which is normal for unauthenticated users
				setUser(null);
			}
		} catch (error) {
			// Only log errors that aren't related to missing sessions
			const errorMessage =
				error instanceof Error ? error.message : String(error);
			if (!errorMessage.includes("Auth session missing")) {
				console.error("Error checking user session:", error);
			}
			setUser(null);
		} finally {
			setLoading(false);
		}
	};

	const signIn = async (email: string, password: string): Promise<void> => {
		setLoading(true);
		try {
			const result = await SupabaseService.signIn(email, password);
			if (!result.success) {
				throw new Error(result.error || "Sign in failed");
			}
			if (result.data) {
				setUser(result.data);
			}
		} catch (error) {
			console.error("Sign in error:", error);
			throw error;
		} finally {
			setLoading(false);
		}
	};

	const signOut = async (): Promise<void> => {
		setLoading(true);
		try {
			const result = await SupabaseService.signOut();
			if (!result.success) {
				throw new Error(result.error || "Sign out failed");
			}
			setUser(null);
		} catch (error) {
			console.error("Sign out error:", error);
			throw error;
		} finally {
			setLoading(false);
		}
	};

	const signUp = async (
		email: string,
		password: string,
		userData: any
	): Promise<void> => {
		setLoading(true);
		try {
			const result = await SupabaseService.signUp(email, password, userData);
			if (!result.success) {
				throw new Error(result.error || "Sign up failed");
			}
			if (result.data) {
				setUser(result.data);
			}
		} catch (error) {
			console.error("Sign up error:", error);
			throw error;
		} finally {
			setLoading(false);
		}
	};
	const value: AuthContextType = {
		user,
		loading,
		signIn,
		signOut,
		signUp,
		setUser,
	};

	return <AuthContext.Provider value={value}>{children}</AuthContext.Provider>;
};

export const useAuth = (): AuthContextType => {
	const context = useContext(AuthContext);
	if (context === undefined) {
		throw new Error("useAuth must be used within an AuthProvider");
	}
	return context;
};
