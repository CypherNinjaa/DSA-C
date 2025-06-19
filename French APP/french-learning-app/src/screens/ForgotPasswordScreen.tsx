// Password Reset Screen
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
} from "react-native";
import { SupabaseService } from "../services/supabaseService";
import { theme } from "../constants/theme";

export const ForgotPasswordScreen = ({ navigation }: any) => {
	const [email, setEmail] = useState("");
	const [loading, setLoading] = useState(false);

	const handlePasswordReset = async () => {
		if (!email.trim()) {
			Alert.alert("Error", "Please enter your email address");
			return;
		}

		setLoading(true);
		try {
			const result = await SupabaseService.resetPassword(email);

			if (result.success) {
				Alert.alert(
					"Password Reset Sent",
					"Check your email for password reset instructions",
					[{ text: "OK", onPress: () => navigation.goBack() }]
				);
			} else {
				Alert.alert(
					"Error",
					result.error || "Failed to send password reset email"
				);
			}
		} catch (error) {
			Alert.alert("Error", "Something went wrong. Please try again.");
		} finally {
			setLoading(false);
		}
	};

	return (
		<KeyboardAvoidingView
			style={styles.container}
			behavior={Platform.OS === "ios" ? "padding" : "height"}
		>
			<View style={styles.content}>
				<Text style={styles.title}>Reset Password</Text>
				<Text style={styles.subtitle}>
					Enter your email address and we'll send you instructions to reset your
					password.
				</Text>

				<View style={styles.inputContainer}>
					<TextInput
						style={styles.input}
						placeholder="Email"
						placeholderTextColor={theme.colors.textSecondary}
						value={email}
						onChangeText={setEmail}
						keyboardType="email-address"
						autoCapitalize="none"
						autoCorrect={false}
					/>
				</View>

				<TouchableOpacity
					style={[styles.button, loading && styles.buttonDisabled]}
					onPress={handlePasswordReset}
					disabled={loading}
				>
					<Text style={styles.buttonText}>
						{loading ? "Sending..." : "Send Reset Email"}
					</Text>
				</TouchableOpacity>

				<TouchableOpacity
					style={styles.backButton}
					onPress={() => navigation.goBack()}
				>
					<Text style={styles.backButtonText}>Back to Login</Text>
				</TouchableOpacity>
			</View>
		</KeyboardAvoidingView>
	);
};

const styles = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: theme.colors.background,
	},
	content: {
		flex: 1,
		justifyContent: "center",
		paddingHorizontal: theme.spacing.lg,
	},
	title: {
		fontSize: theme.typography.heading.fontSize,
		fontWeight: theme.typography.heading.fontWeight,
		color: theme.colors.primary,
		textAlign: "center",
		marginBottom: theme.spacing.md,
	},
	subtitle: {
		fontSize: theme.typography.body.fontSize,
		fontWeight: theme.typography.body.fontWeight,
		color: theme.colors.textSecondary,
		textAlign: "center",
		marginBottom: theme.spacing.xl,
		lineHeight: 22,
	},
	inputContainer: {
		marginBottom: theme.spacing.lg,
	},
	input: {
		borderWidth: 1,
		borderColor: theme.colors.textSecondary,
		borderRadius: 8,
		paddingHorizontal: theme.spacing.md,
		paddingVertical: theme.spacing.sm,
		fontSize: theme.typography.body.fontSize,
		fontWeight: theme.typography.body.fontWeight,
		backgroundColor: theme.colors.surface,
	},
	button: {
		backgroundColor: theme.colors.primary,
		paddingVertical: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		marginBottom: theme.spacing.lg,
	},
	buttonDisabled: {
		backgroundColor: theme.colors.textSecondary,
	},
	buttonText: {
		color: theme.colors.surface,
		fontSize: theme.typography.body.fontSize,
		fontWeight: theme.typography.subheading.fontWeight,
	},
	backButton: {
		alignItems: "center",
		paddingVertical: theme.spacing.sm,
	},
	backButtonText: {
		color: theme.colors.primary,
		fontSize: theme.typography.body.fontSize,
		fontWeight: theme.typography.subheading.fontWeight,
	},
});
