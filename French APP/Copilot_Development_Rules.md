# GitHub Copilot Rules for French Learning App Development

## 🎯 Project Context & Guidelines

### Core Project Information
- **Project Name:** FrenchLearningApp
- **Developer:** CypherNinjaa
- **Start Date:** 2025-06-19
- **Tech Stack:** React Native (Expo), Supabase, Groq AI, TypeScript
- **Current Stage:** Stage 1 - Project Foundation & Setup

### Development Philosophy
- Build incrementally following the roadmap stages
- Prioritize code quality and maintainability
- Implement TypeScript for type safety
- Follow React Native and Expo best practices
- Maintain consistent coding standards

---

## 📁 Project Structure Rules

### Folder Organization
```
FrenchLearningApp/
├── src/
│   ├── components/          # Reusable UI components
│   ├── screens/            # Screen components
│   ├── navigation/         # Navigation configuration
│   ├── services/           # API and external service integrations
│   ├── hooks/              # Custom React hooks
│   ├── utils/              # Utility functions
│   ├── types/              # TypeScript type definitions
│   ├── constants/          # App constants and configuration
│   └── contexts/           # React contexts for state management
├── assets/                 # Images, fonts, sounds
├── docs/                   # Documentation
└── tests/                  # Test files
```

### File Naming Conventions
- **Components:** PascalCase (e.g., `LessonCard.tsx`)
- **Screens:** PascalCase with Screen suffix (e.g., `HomeScreen.tsx`)
- **Services:** camelCase (e.g., `supabaseService.ts`)
- **Hooks:** camelCase with use prefix (e.g., `useAuth.ts`)
- **Types:** PascalCase with Type suffix (e.g., `UserType.ts`)

---

## 🔧 Coding Standards & Rules

### TypeScript Rules
```typescript
// Always use TypeScript interfaces for data structures
interface User {
  id: string;
  username: string;
  email: string;
  level: 'beginner' | 'intermediate' | 'advanced';
  points: number;
  streakDays: number;
  createdAt: string;
}

// Use enums for constants
enum LessonType {
  VOCABULARY = 'vocabulary',
  GRAMMAR = 'grammar',
  PRONUNCIATION = 'pronunciation',
  CONVERSATION = 'conversation'
}

// Always type function parameters and return values
const getUserProgress = async (userId: string): Promise<UserProgress[]> => {
  // Implementation
};
```

### Component Structure Rules
```typescript
// Always use functional components with TypeScript
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

interface ComponentNameProps {
  title: string;
  onPress?: () => void;
  isActive?: boolean;
}

export const ComponentName: React.FC<ComponentNameProps> = ({
  title,
  onPress,
  isActive = false
}) => {
  return (
    <View style={[styles.container, isActive && styles.active]}>
      <Text style={styles.title}>{title}</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    padding: 16,
    backgroundColor: '#fff',
  },
  active: {
    backgroundColor: '#007AFF',
  },
  title: {
    fontSize: 16,
    fontWeight: '600',
  },
});
```

### Service Layer Rules
```typescript
// All API calls should go through service layer
// services/supabaseService.ts
import { supabase } from '../config/supabase';

export class SupabaseService {
  static async getUser(userId: string): Promise<User | null> {
    try {
      const { data, error } = await supabase
        .from('profiles')
        .select('*')
        .eq('id', userId)
        .single();
      
      if (error) throw error;
      return data;
    } catch (error) {
      console.error('Error fetching user:', error);
      return null;
    }
  }
}
```

---

## 🗃️ Database Schema Rules

### Supabase Table Naming
- Use snake_case for table and column names
- Always include `created_at` and `updated_at` timestamps
- Use meaningful foreign key names
- Include proper indexes for performance

### Example Schema Pattern
```sql
-- Follow this pattern for all tables
CREATE TABLE table_name (
  id SERIAL PRIMARY KEY,
  user_id UUID REFERENCES auth.users(id) ON DELETE CASCADE,
  title TEXT NOT NULL,
  description TEXT,
  is_active BOOLEAN DEFAULT true,
  created_at TIMESTAMP WITH TIME ZONE DEFAULT NOW(),
  updated_at TIMESTAMP WITH TIME ZONE DEFAULT NOW()
);

-- Always create updated_at trigger
CREATE OR REPLACE FUNCTION update_updated_at_column()
RETURNS TRIGGER AS $$
BEGIN
  NEW.updated_at = NOW();
  RETURN NEW;
END;
$$ language 'plpgsql';

CREATE TRIGGER update_table_name_updated_at 
  BEFORE UPDATE ON table_name 
  FOR EACH ROW EXECUTE FUNCTION update_updated_at_column();
```

---

## 🎨 UI/UX Rules

### Design System
```typescript
// constants/theme.ts
export const theme = {
  colors: {
    primary: '#007AFF',
    secondary: '#5856D6',
    success: '#34C759',
    warning: '#FF9500',
    error: '#FF3B30',
    background: '#F2F2F7',
    surface: '#FFFFFF',
    text: '#000000',
    textSecondary: '#8E8E93',
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
      fontWeight: '700',
    },
    subheading: {
      fontSize: 18,
      fontWeight: '600',
    },
    body: {
      fontSize: 16,
      fontWeight: '400',
    },
  },
};
```

### Component Reusability Rules
- Create atomic components for buttons, inputs, cards
- Use consistent spacing and colors from theme
- Always make components configurable with props
- Include loading and error states

---

## 🚦 Stage-Specific Development Rules

### Current Stage Rules (Stage 1: Foundation)
```typescript
// Focus areas for Stage 1:
// 1. Authentication flow
// 2. Basic navigation
// 3. Supabase connection
// 4. Project structure setup

// Example: Authentication context
interface AuthContextType {
  user: User | null;
  loading: boolean;
  signIn: (email: string, password: string) => Promise<void>;
  signOut: () => Promise<void>;
  signUp: (email: string, password: string, userData: any) => Promise<void>;
}
```

---

## 🔄 Progressive Development Rules

### Roadmap Adherence
1. **Complete current stage before moving to next**
2. **Test each feature before implementation**
3. **Document API endpoints and components**
4. **Maintain backward compatibility**
5. **Regular commits with descriptive messages**

### Git Commit Message Format
```
type(scope): description

Types: feat, fix, docs, style, refactor, test, chore
Scope: auth, ui, api, db, etc.

Examples:
feat(auth): implement user registration flow
fix(ui): resolve lesson card layout issue
docs(api): add Supabase service documentation
```

---

## 🧪 Testing Rules

### Test Coverage Requirements
```typescript
// Always test critical functions
// __tests__/services/authService.test.ts
import { AuthService } from '../src/services/authService';

describe('AuthService', () => {
  test('should authenticate user with valid credentials', async () => {
    // Test implementation
  });
  
  test('should handle authentication errors', async () => {
    // Test implementation
  });
});
```

---

## 🔐 Security Rules

### Data Handling
- Never store sensitive data in AsyncStorage
- Always validate user input
- Use Supabase RLS (Row Level Security)
- Sanitize data before database operations

### API Security
```typescript
// Always handle errors gracefully
const handleApiCall = async <T>(
  apiCall: () => Promise<T>
): Promise<T | null> => {
  try {
    return await apiCall();
  } catch (error) {
    console.error('API Error:', error);
    // Log to monitoring service
    return null;
  }
};
```

---

## 🎯 AI Integration Rules (Groq)

### Groq Service Structure
```typescript
// services/groqService.ts
interface GroqResponse {
  content: string;
  usage: {
    tokens: number;
    cost: number;
  };
}

export class GroqService {
  private static readonly API_URL = 'https://api.groq.com/v1';
  
  static async generateContent(
    prompt: string,
    context: any
  ): Promise<GroqResponse | null> {
    // Implementation with error handling
  }
}
```

---

## 📱 React Native Specific Rules

### Performance Optimization
- Use FlatList for long lists
- Implement lazy loading for images
- Use React.memo for expensive components
- Optimize bundle size with tree shaking

### Platform-Specific Code
```typescript
import { Platform } from 'react-native';

const styles = StyleSheet.create({
  container: {
    ...Platform.select({
      ios: {
        shadowColor: '#000',
        shadowOffset: { width: 0, height: 2 },
        shadowOpacity: 0.25,
      },
      android: {
        elevation: 5,
      },
    }),
  },
});
```

---

## 📊 Progress Tracking

### Development Milestones
- [ ] Stage 1: Authentication & Setup (Current)
- [ ] Stage 2: User Management
- [ ] Stage 3: Content Management
- [ ] Stage 4: Core Learning Features
- [ ] Stage 5: Pronunciation Features
- [ ] Stage 6: AI Integration
- [ ] Stage 7: UI/UX Polish
- [ ] Stage 8: Analytics
- [ ] Stage 9: Testing
- [ ] Stage 10: Advanced Features
- [ ] Stage 11: Deployment
- [ ] Stage 12: Maintenance

### Daily Goals Template
```markdown
## Daily Development Log - YYYY-MM-DD
### Completed:
- [ ] Task 1
- [ ] Task 2

### In Progress:
- [ ] Task 3

### Next Steps:
- [ ] Task 4
- [ ] Task 5

### Blockers:
- Issue description and potential solutions
```

---

## 🤖 Copilot Interaction Guidelines

### When Asking for Code Generation
1. **Always specify the current stage and context**
2. **Mention the specific roadmap requirement**
3. **Include TypeScript types and interfaces**
4. **Request error handling and edge cases**
5. **Ask for comments and documentation**

### Example Prompts
```
"Generate a TypeScript authentication service for Stage 1 of the French learning app. 
Include sign in, sign up, and sign out methods using Supabase. 
Follow the project structure rules and include proper error handling."

"Create a React Native screen component for the lesson list in Stage 4. 
Use TypeScript, follow the component structure rules, and include loading states. 
The screen should display lessons from Supabase with proper navigation."
```

---

## 📋 Quality Checklist

### Before Each Commit
- [ ] Code follows TypeScript standards
- [ ] Components are properly typed
- [ ] Error handling is implemented
- [ ] Code is documented with comments
- [ ] No console errors or warnings
- [ ] Follows project structure rules
- [ ] Adheres to current stage requirements

### Before Stage Completion
- [ ] All stage deliverables completed
- [ ] Code tested on both iOS and Android
- [ ] Documentation updated
- [ ] Database schema properly implemented
- [ ] API endpoints tested
- [ ] User experience validated

This comprehensive rule set will help GitHub Copilot understand your project context and generate code that aligns with your development roadmap and coding standards.