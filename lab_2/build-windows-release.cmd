set SCRIPT_DIR=%~dp0 
echo "build-windows-release.cmd located in: %SCRIPT_DIR%

cd %SCRIPT_DIR%
if exist "build-windows-release"(
    rmdir /s "build-windows-release"
)
mkdir "build-windows-release"
cmake -S . -B "build-windows-release" -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles"

echo "=== cmake end ==="

cd "build-windows-release"
mingw32-make
echo "build-windows-release was completed"