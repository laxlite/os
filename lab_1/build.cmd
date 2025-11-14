@echo off

set SCRIPT_DIR=%~dp0
echo build.cmd located in: %SCRIPT_DIR%


cd ..
git add *
set /p message=Текст коммита: 
git commit -m "%message%"
cd lab_1
if exist build (
    rmdir /s /q build
)
mkdir build
cmake -S . -B build
cd build
mingw32-make
echo Сборка завершена
pause