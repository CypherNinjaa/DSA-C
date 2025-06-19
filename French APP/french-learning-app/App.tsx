import React from "react";
import { StatusBar } from "expo-status-bar";
import { SafeAreaProvider } from "react-native-safe-area-context";
import { AuthProvider } from "./src/contexts/AuthContext";
import { AppNavigation } from "./src/navigation/AppNavigation";

export default function App() {
	return (
		<SafeAreaProvider>
			<AuthProvider>
				<AppNavigation />
				<StatusBar style="auto" />
			</AuthProvider>
		</SafeAreaProvider>
	);
}
