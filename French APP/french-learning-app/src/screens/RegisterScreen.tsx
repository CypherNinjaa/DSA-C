import React, { useState } from "react";
import {
	View,
	Text,
	TextInput,
	TouchableOpacity,
	StyleSheet,
	Alert,
	KeyboardAvoidingView,
	Platform,
	ScrollView,
} from "react-native";
import { useAuth } from "../contexts/AuthContext";
import { theme } from "../constants/theme";

interface RegisterScreenProps {
	navigation: any; // Will be properly typed with navigation types later
}

export const RegisterScreen: React.FC<RegisterScreenProps> = ({
	navigation,
}) => {
	const [email, setEmail] = useState("");
	const [password, setPassword] = useState("");
	const [confirmPassword, setConfirmPassword] = useState("");
	const [username, setUsername] = useState("");
	const [fullName, setFullName] = useState("");
	const { signUp, loading } = useAuth();

	const handleRegister = async () => {
		if (!email || !password || !confirmPassword || !username || !fullName) {
			Alert.alert("Error", "Please fill in all fields");
			return;
		}

		if (password !== confirmPassword) {
			Alert.alert("Error", "Passwords do not match");
			return;
		}

		if (password.length < 6) {
			Alert.alert("Error", "Password must be at least 6 characters long");
			return;
		}

		try {
			await signUp(email, password, {
				username,
				full_name: fullName,
			});
		} catch (error) {
			Alert.alert(
				"Registration Error",
				error instanceof Error ? error.message : "Unknown error occurred"
			);
		}
	};

	const navigateToLogin = () => {
		navigation.navigate("Login");
	};

	return (
		<KeyboardAvoidingView
			style={styles.container}
			behavior={Platform.OS === "ios" ? "padding" : "height"}
		>
			<ScrollView contentContainerStyle={styles.scrollContainer}>
				<View style={styles.headerContainer}>
					<Text style={styles.title}>Join FrenchMaster!</Text>
					<Text style={styles.subtitle}>
						Create your account to start learning French
					</Text>
				</View>

				<View style={styles.formContainer}>
					<View style={styles.inputContainer}>
						<Text style={styles.label}>Full Name</Text>
						<TextInput
							style={styles.input}
							value={fullName}
							onChangeText={setFullName}
							placeholder="Enter your full name"
							autoCapitalize="words"
						/>
					</View>

					<View style={styles.inputContainer}>
						<Text style={styles.label}>Username</Text>
						<TextInput
							style={styles.input}
							value={username}
							onChangeText={setUsername}
							placeholder="Choose a username"
							autoCapitalize="none"
							autoCorrect={false}
						/>
					</View>

					<View style={styles.inputContainer}>
						<Text style={styles.label}>Email</Text>
						<TextInput
							style={styles.input}
							value={email}
							onChangeText={setEmail}
							placeholder="Enter your email"
							keyboardType="email-address"
							autoCapitalize="none"
							autoCorrect={false}
						/>
					</View>

					<View style={styles.inputContainer}>
						<Text style={styles.label}>Password</Text>
						<TextInput
							style={styles.input}
							value={password}
							onChangeText={setPassword}
							placeholder="Create a password (min. 6 characters)"
							secureTextEntry
							autoCapitalize="none"
						/>
					</View>

					<View style={styles.inputContainer}>
						<Text style={styles.label}>Confirm Password</Text>
						<TextInput
							style={styles.input}
							value={confirmPassword}
							onChangeText={setConfirmPassword}
							placeholder="Confirm your password"
							secureTextEntry
							autoCapitalize="none"
						/>
					</View>

					<TouchableOpacity
						style={[styles.button, loading && styles.buttonDisabled]}
						onPress={handleRegister}
						disabled={loading}
					>
						<Text style={styles.buttonText}>
							{loading ? "Creating Account..." : "Create Account"}
						</Text>
					</TouchableOpacity>

					<View style={styles.loginContainer}>
						<Text style={styles.loginText}>Already have an account? </Text>
						<TouchableOpacity onPress={navigateToLogin}>
							<Text style={styles.loginLink}>Sign In</Text>
						</TouchableOpacity>
					</View>
				</View>
			</ScrollView>
		</KeyboardAvoidingView>
	);
};

const styles = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: theme.colors.background,
	},
	scrollContainer: {
		flexGrow: 1,
		justifyContent: "center",
		padding: theme.spacing.lg,
	},
	headerContainer: {
		alignItems: "center",
		marginBottom: theme.spacing.xl,
	},
	title: {
		...theme.typography.heading,
		color: theme.colors.text,
		marginBottom: theme.spacing.sm,
	},
	subtitle: {
		...theme.typography.body,
		color: theme.colors.textSecondary,
		textAlign: "center",
	},
	formContainer: {
		backgroundColor: theme.colors.surface,
		padding: theme.spacing.lg,
		borderRadius: 12,
		shadowColor: "#000",
		shadowOffset: {
			width: 0,
			height: 2,
		},
		shadowOpacity: 0.1,
		shadowRadius: 3.84,
		elevation: 5,
	},
	inputContainer: {
		marginBottom: theme.spacing.md,
	},
	label: {
		...theme.typography.body,
		color: theme.colors.text,
		marginBottom: theme.spacing.xs,
		fontWeight: "600",
	},
	input: {
		borderWidth: 1,
		borderColor: "#E1E1E1",
		borderRadius: 8,
		padding: theme.spacing.md,
		fontSize: 16,
		backgroundColor: theme.colors.surface,
	},
	button: {
		backgroundColor: theme.colors.primary,
		padding: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		marginTop: theme.spacing.md,
	},
	buttonDisabled: {
		opacity: 0.6,
	},
	buttonText: {
		color: theme.colors.surface,
		fontSize: 16,
		fontWeight: "600",
	},
	loginContainer: {
		flexDirection: "row",
		justifyContent: "center",
		marginTop: theme.spacing.lg,
	},
	loginText: {
		...theme.typography.body,
		color: theme.colors.textSecondary,
	},
	loginLink: {
		...theme.typography.body,
		color: theme.colors.primary,
		fontWeight: "600",
	},
});
