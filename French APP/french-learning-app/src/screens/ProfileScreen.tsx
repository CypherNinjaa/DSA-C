// Enhanced Profile Screen with Stage 2 features
import React, { useState, useEffect } from "react";
import {
	View,
	Text,
	StyleSheet,
	TouchableOpacity,
	TextInput,
	Alert,
	ScrollView,
	Image,
} from "react-native";
import { useAuth } from "../contexts/AuthContext";
import { SupabaseService } from "../services/supabaseService";
import { theme } from "../constants/theme";
import { User } from "../types";

export const ProfileScreen = ({ navigation }: any) => {
	const { user, setUser } = useAuth();
	const [loading, setLoading] = useState(false);
	const [editing, setEditing] = useState(false);
	const [formData, setFormData] = useState({
		username: user?.username || "",
		email: user?.email || "",
		level: user?.level || "beginner",
	});

	const handleSave = async () => {
		if (!user) return;

		setLoading(true);
		try {
			const result = await SupabaseService.updateUserProfile(user.id, {
				username: formData.username,
				level: formData.level,
			});

			if (result.success && result.data) {
				// Update user context
				const updatedUser: User = {
					...user,
					username: result.data.username || user.username,
					level: result.data.level as "beginner" | "intermediate" | "advanced",
				};
				setUser(updatedUser);
				setEditing(false);
				Alert.alert("Success", "Profile updated successfully!");
			} else {
				Alert.alert("Error", result.error || "Failed to update profile");
			}
		} catch (error) {
			Alert.alert("Error", "Something went wrong. Please try again.");
		} finally {
			setLoading(false);
		}
	};

	const handleSignOut = async () => {
		Alert.alert("Sign Out", "Are you sure you want to sign out?", [
			{ text: "Cancel", style: "cancel" },
			{
				text: "Sign Out",
				style: "destructive",
				onPress: async () => {
					const result = await SupabaseService.signOut();
					if (!result.success) {
						Alert.alert("Error", "Failed to sign out");
					}
				},
			},
		]);
	};

	if (!user) {
		return (
			<View style={styles.container}>
				<Text style={styles.errorText}>No user data available</Text>
			</View>
		);
	}

	return (
		<ScrollView style={styles.container}>
			<View style={styles.header}>
				<View style={styles.avatarContainer}>
					<View style={styles.avatar}>
						<Text style={styles.avatarText}>
							{user.username.charAt(0).toUpperCase()}
						</Text>
					</View>
				</View>
				<Text style={styles.welcomeText}>Welcome back!</Text>
			</View>

			<View style={styles.statsContainer}>
				<View style={styles.statItem}>
					<Text style={styles.statNumber}>{user.points}</Text>
					<Text style={styles.statLabel}>Points</Text>
				</View>
				<View style={styles.statItem}>
					<Text style={styles.statNumber}>{user.streakDays}</Text>
					<Text style={styles.statLabel}>Day Streak</Text>
				</View>
				<View style={styles.statItem}>
					<Text style={styles.statLabel}>Level</Text>
					<Text style={styles.levelBadge}>{user.level.toUpperCase()}</Text>
				</View>
			</View>

			<View style={styles.section}>
				<View style={styles.sectionHeader}>
					<Text style={styles.sectionTitle}>Profile Information</Text>
					<TouchableOpacity
						onPress={() => {
							if (editing) {
								setFormData({
									username: user.username,
									email: user.email,
									level: user.level,
								});
							}
							setEditing(!editing);
						}}
					>
						<Text style={styles.editButton}>{editing ? "Cancel" : "Edit"}</Text>
					</TouchableOpacity>
				</View>

				<View style={styles.inputContainer}>
					<Text style={styles.label}>Username</Text>
					<TextInput
						style={[styles.input, !editing && styles.inputDisabled]}
						value={formData.username}
						onChangeText={(text) =>
							setFormData({ ...formData, username: text })
						}
						editable={editing}
						placeholder="Enter username"
					/>
				</View>

				<View style={styles.inputContainer}>
					<Text style={styles.label}>Email</Text>
					<TextInput
						style={[styles.input, styles.inputDisabled]}
						value={formData.email}
						editable={false}
						placeholder="Email address"
					/>
				</View>

				<View style={styles.inputContainer}>
					<Text style={styles.label}>Learning Level</Text>
					<View style={styles.levelSelector}>
						{["beginner", "intermediate", "advanced"].map((level) => (
							<TouchableOpacity
								key={level}
								style={[
									styles.levelOption,
									formData.level === level && styles.levelOptionSelected,
									!editing && styles.levelOptionDisabled,
								]}
								onPress={() =>
									editing &&
									setFormData({
										...formData,
										level: level as "beginner" | "intermediate" | "advanced",
									})
								}
								disabled={!editing}
							>
								<Text
									style={[
										styles.levelOptionText,
										formData.level === level && styles.levelOptionTextSelected,
									]}
								>
									{level.charAt(0).toUpperCase() + level.slice(1)}
								</Text>
							</TouchableOpacity>
						))}
					</View>
				</View>

				{editing && (
					<TouchableOpacity
						style={[styles.saveButton, loading && styles.buttonDisabled]}
						onPress={handleSave}
						disabled={loading}
					>
						<Text style={styles.saveButtonText}>
							{loading ? "Saving..." : "Save Changes"}
						</Text>
					</TouchableOpacity>
				)}
			</View>

			<View style={styles.section}>
				<Text style={styles.sectionTitle}>Account Actions</Text>

				<TouchableOpacity style={styles.actionButton} onPress={handleSignOut}>
					<Text style={styles.actionButtonText}>Sign Out</Text>
				</TouchableOpacity>
			</View>

			<View style={styles.footer}>
				<Text style={styles.footerText}>
					Member since {new Date(user.createdAt).toLocaleDateString()}
				</Text>
			</View>
		</ScrollView>
	);
};

const styles = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: theme.colors.background,
	},
	header: {
		alignItems: "center",
		paddingVertical: theme.spacing.xl,
		backgroundColor: theme.colors.surface,
		marginBottom: theme.spacing.md,
	},
	avatarContainer: {
		marginBottom: theme.spacing.md,
	},
	avatar: {
		width: 80,
		height: 80,
		borderRadius: 40,
		backgroundColor: theme.colors.primary,
		justifyContent: "center",
		alignItems: "center",
	},
	avatarText: {
		fontSize: 32,
		fontWeight: "bold",
		color: theme.colors.surface,
	},
	welcomeText: {
		fontSize: theme.typography.heading.fontSize,
		fontWeight: theme.typography.heading.fontWeight,
		color: theme.colors.text,
	},
	statsContainer: {
		flexDirection: "row",
		justifyContent: "space-around",
		backgroundColor: theme.colors.surface,
		paddingVertical: theme.spacing.lg,
		marginBottom: theme.spacing.md,
	},
	statItem: {
		alignItems: "center",
	},
	statNumber: {
		fontSize: 24,
		fontWeight: "bold",
		color: theme.colors.primary,
		marginBottom: theme.spacing.xs,
	},
	statLabel: {
		fontSize: theme.typography.body.fontSize,
		color: theme.colors.textSecondary,
	},
	levelBadge: {
		fontSize: 12,
		fontWeight: "bold",
		color: theme.colors.surface,
		backgroundColor: theme.colors.success,
		paddingHorizontal: theme.spacing.sm,
		paddingVertical: theme.spacing.xs,
		borderRadius: 4,
		marginTop: theme.spacing.xs,
	},
	section: {
		backgroundColor: theme.colors.surface,
		marginBottom: theme.spacing.md,
		paddingHorizontal: theme.spacing.lg,
		paddingVertical: theme.spacing.lg,
	},
	sectionHeader: {
		flexDirection: "row",
		justifyContent: "space-between",
		alignItems: "center",
		marginBottom: theme.spacing.lg,
	},
	sectionTitle: {
		fontSize: theme.typography.subheading.fontSize,
		fontWeight: theme.typography.subheading.fontWeight,
		color: theme.colors.text,
	},
	editButton: {
		color: theme.colors.primary,
		fontWeight: "600",
	},
	inputContainer: {
		marginBottom: theme.spacing.md,
	},
	label: {
		fontSize: theme.typography.body.fontSize,
		fontWeight: "600",
		color: theme.colors.text,
		marginBottom: theme.spacing.xs,
	},
	input: {
		borderWidth: 1,
		borderColor: theme.colors.textSecondary,
		borderRadius: 8,
		paddingHorizontal: theme.spacing.md,
		paddingVertical: theme.spacing.sm,
		fontSize: theme.typography.body.fontSize,
		backgroundColor: theme.colors.surface,
	},
	inputDisabled: {
		backgroundColor: theme.colors.background,
		color: theme.colors.textSecondary,
	},
	levelSelector: {
		flexDirection: "row",
		justifyContent: "space-between",
	},
	levelOption: {
		flex: 1,
		paddingVertical: theme.spacing.sm,
		borderWidth: 1,
		borderColor: theme.colors.textSecondary,
		borderRadius: 8,
		alignItems: "center",
		marginHorizontal: 2,
	},
	levelOptionSelected: {
		backgroundColor: theme.colors.primary,
		borderColor: theme.colors.primary,
	},
	levelOptionDisabled: {
		opacity: 0.6,
	},
	levelOptionText: {
		fontSize: theme.typography.body.fontSize,
		color: theme.colors.text,
	},
	levelOptionTextSelected: {
		color: theme.colors.surface,
		fontWeight: "600",
	},
	saveButton: {
		backgroundColor: theme.colors.primary,
		paddingVertical: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		marginTop: theme.spacing.lg,
	},
	buttonDisabled: {
		backgroundColor: theme.colors.textSecondary,
	},
	saveButtonText: {
		color: theme.colors.surface,
		fontSize: theme.typography.body.fontSize,
		fontWeight: "600",
	},
	actionButton: {
		paddingVertical: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		backgroundColor: theme.colors.error,
	},
	actionButtonText: {
		color: theme.colors.surface,
		fontSize: theme.typography.body.fontSize,
		fontWeight: "600",
	},
	footer: {
		alignItems: "center",
		paddingVertical: theme.spacing.xl,
	},
	footerText: {
		fontSize: theme.typography.body.fontSize,
		color: theme.colors.textSecondary,
	},
	errorText: {
		fontSize: theme.typography.body.fontSize,
		color: theme.colors.error,
		textAlign: "center",
		marginTop: theme.spacing.xl,
	},
});
