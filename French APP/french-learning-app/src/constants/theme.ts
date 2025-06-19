// Theme constants following the development rules
export const theme = {
	colors: {
		primary: "#007AFF",
		secondary: "#5856D6",
		success: "#34C759",
		warning: "#FF9500",
		error: "#FF3B30",
		background: "#F2F2F7",
		surface: "#FFFFFF",
		text: "#000000",
		textSecondary: "#8E8E93",
	},
	spacing: {
		xs: 4,
		sm: 8,
		md: 16,
		lg: 24,
		xl: 32,
	},
	typography: {
		heading: {
			fontSize: 24,
			fontWeight: "700" as "700",
		},
		subheading: {
			fontSize: 18,
			fontWeight: "600" as "600",
		},
		body: {
			fontSize: 16,
			fontWeight: "400" as "400",
		},
	},
};

export type Theme = typeof theme;
