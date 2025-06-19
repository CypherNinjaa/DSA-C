@echo off
echo Setting up Supabase environment for French Learning App...
echo.

if not exist .env (
    echo Creating .env file from template...
    copy .env.example .env
    echo.
    echo ✅ .env file created!
    echo.
    echo ⚠️  IMPORTANT: Please edit .env file and add your Supabase credentials:
    echo    1. Go to https://supabase.com/dashboard
    echo    2. Select your French Learning App project
    echo    3. Go to Settings → API
    echo    4. Copy Project URL and Anon Key to .env file
    echo.
) else (
    echo .env file already exists!
    echo.
)

echo Next steps:
echo 1. Edit .env with your Supabase credentials
echo 2. Run the SQL schema in Supabase Dashboard
echo 3. Test the app with: npm start
echo.
echo For detailed instructions, see: supabase\SETUP.md
pause
