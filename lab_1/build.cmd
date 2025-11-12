@echo off
git add *
set /p message=Текст коммита: 
git commit -m "%message%"
if exist build (
    rmdir /s /q build
)
mkdir build
cmake -S . -B build
cd build
mingw32-make
echo Сборка завершена
pause