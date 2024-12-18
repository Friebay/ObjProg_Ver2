@echo off
REM Delete previous build directory if it exists
if exist build (
    echo Removing existing build directory...
    rmdir /S /Q build
)

REM Create build directory
echo Creating build directory...
mkdir build
cd build

REM Run CMake to generate Release build files
echo Configuring CMake for Release build...
cmake -DCMAKE_BUILD_TYPE=Release ..

REM Build the program
echo Building the program...
cmake --build . --config Release

REM Check if the program was built successfully in \build\Release
if exist "Release\program.exe" (
<<<<<<< Updated upstream
    REM Move and rename executable to the main directory, then clean up
    echo Moving and renaming executable to cmake_compiled_program.exe in main directory...
    move /Y "Release\program.exe" "..\cmake_compiled_program.exe"
=======
    REM Copy manifest first
    copy /Y "..\StudPazSkaiciuokle.manifest" "Release\program.exe.manifest"
    
    REM Embed manifest using mt.exe
    mt.exe -manifest "Release\program.exe.manifest" -outputresource:"Release\program.exe";1
    
    REM Move and rename executable
    move /Y "Release\program.exe" "..\StudPazSkaiciuokle.exe"
>>>>>>> Stashed changes
) else (
    echo Build failed or program.exe not found in build\Release directory.
    pause
    exit /b 1
)

cd ..
rmdir /S /Q build

echo Build complete! The program executable is ready as cmake_compiled_program.exe.
pause
