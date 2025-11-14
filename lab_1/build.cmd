@echo off

set SCRIPT_DIR=%~dp0
echo build.cmd located in: %SCRIPT_DIR%

cd %SCRIPT_DIR%
cd ..
git add *
set /p message=Commit description: 
git commit -m "%message%"
cd lab_1
if exist build-windows (
    rmdir /s /q build-windows
)
mkdir build-windows
cmake -S . -B build-windows -G "MinGW Makefiles"
cd build-windows
mingw32-make
echo Build was completed