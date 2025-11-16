set SCRIPT_DIR=%~dp0 
echo "build-windows-debug.cmd located in: %SCRIPT_DIR%

cd %SCRIPT_DIR%
if exist "build-windows-debug"(
    rmdir /s "build-windows-debug"
)
mkdir "build-windows-debug"
cmake -S . -B "build-windows-debug" -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles"

echo "=== cmake end ==="

cd "build-windows-debug"
mingw32-make
echo "build-windows-debug was completed"