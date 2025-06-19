import React from "react";
import {
	View,
	Text,
	TouchableOpacity,
	StyleSheet,
	SafeAreaView,
} from "react-native";
import { useAuth } from "../contexts/AuthContext";
import { theme } from "../constants/theme";

interface HomeScreenProps {
	navigation: any; // Will be properly typed with navigation types later
}

export const HomeScreen: React.FC<HomeScreenProps> = ({ navigation }) => {
	const { user, signOut } = useAuth();

	const handleSignOut = async () => {
		try {
			await signOut();
		} catch (error) {
			console.error("Sign out error:", error);
		}
	};

	return (
		<SafeAreaView style={styles.container}>
			<View style={styles.content}>
				<View style={styles.headerContainer}>
					<Text style={styles.welcomeText}>
						Bonjour, {user?.username || user?.email}!
					</Text>
					<Text style={styles.subtitle}>
						Ready to continue your French learning journey?
					</Text>
				</View>
				<View style={styles.statsContainer}>
					<View style={styles.statItem}>
						<Text style={styles.statNumber}>{user?.points || 0}</Text>
						<Text style={styles.statLabel}>Points</Text>
					</View>
					<View style={styles.statItem}>
						<Text style={styles.statNumber}>{user?.streakDays || 0}</Text>
						<Text style={styles.statLabel}>Day Streak</Text>
					</View>
					<View style={styles.statItem}>
						<Text style={styles.statLevel}>{user?.level || "beginner"}</Text>
						<Text style={styles.statLabel}>Level</Text>
					</View>
				</View>{" "}
				<View style={styles.buttonContainer}>
					<TouchableOpacity style={styles.primaryButton}>
						<Text style={styles.primaryButtonText}>Start Learning</Text>
					</TouchableOpacity>

					<TouchableOpacity
						style={styles.secondaryButton}
						onPress={() => navigation.navigate("Profile")}
					>
						<Text style={styles.secondaryButtonText}>View Profile</Text>
					</TouchableOpacity>

					<TouchableOpacity style={styles.secondaryButton}>
						<Text style={styles.secondaryButtonText}>View Progress</Text>
					</TouchableOpacity>

					<TouchableOpacity style={styles.secondaryButton}>
						<Text style={styles.secondaryButtonText}>
							Practice Pronunciation
						</Text>
					</TouchableOpacity>
				</View>
				<TouchableOpacity style={styles.signOutButton} onPress={handleSignOut}>
					<Text style={styles.signOutText}>Sign Out</Text>
				</TouchableOpacity>
			</View>
		</SafeAreaView>
	);
};

const styles = StyleSheet.create({
	container: {
		flex: 1,
		backgroundColor: theme.colors.background,
	},
	content: {
		flex: 1,
		padding: theme.spacing.lg,
	},
	headerContainer: {
		alignItems: "center",
		marginBottom: theme.spacing.xl,
		marginTop: theme.spacing.lg,
	},
	welcomeText: {
		...theme.typography.heading,
		color: theme.colors.text,
		marginBottom: theme.spacing.sm,
		textAlign: "center",
	},
	subtitle: {
		...theme.typography.body,
		color: theme.colors.textSecondary,
		textAlign: "center",
	},
	statsContainer: {
		flexDirection: "row",
		justifyContent: "space-around",
		backgroundColor: theme.colors.surface,
		padding: theme.spacing.lg,
		borderRadius: 12,
		marginBottom: theme.spacing.xl,
		shadowColor: "#000",
		shadowOffset: {
			width: 0,
			height: 2,
		},
		shadowOpacity: 0.1,
		shadowRadius: 3.84,
		elevation: 5,
	},
	statItem: {
		alignItems: "center",
	},
	statNumber: {
		fontSize: 24,
		fontWeight: "700",
		color: theme.colors.primary,
		marginBottom: theme.spacing.xs,
	},
	statLevel: {
		fontSize: 16,
		fontWeight: "600",
		color: theme.colors.primary,
		marginBottom: theme.spacing.xs,
		textTransform: "capitalize",
	},
	statLabel: {
		...theme.typography.body,
		color: theme.colors.textSecondary,
		fontSize: 14,
	},
	buttonContainer: {
		flex: 1,
		justifyContent: "center",
	},
	primaryButton: {
		backgroundColor: theme.colors.primary,
		padding: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		marginBottom: theme.spacing.md,
	},
	primaryButtonText: {
		color: theme.colors.surface,
		fontSize: 16,
		fontWeight: "600",
	},
	secondaryButton: {
		backgroundColor: theme.colors.surface,
		padding: theme.spacing.md,
		borderRadius: 8,
		alignItems: "center",
		marginBottom: theme.spacing.md,
		borderWidth: 1,
		borderColor: theme.colors.primary,
	},
	secondaryButtonText: {
		color: theme.colors.primary,
		fontSize: 16,
		fontWeight: "600",
	},
	signOutButton: {
		alignItems: "center",
		padding: theme.spacing.sm,
	},
	signOutText: {
		color: theme.colors.error,
		fontSize: 16,
		fontWeight: "600",
	},
});
