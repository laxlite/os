git add .
read -p "Текст коммита: " message
git commit -m "$message"

cd lab_1

if [ -d "build" ]; then
    rm -rf build;
fi
mkdir build
cmake -S . -B build
cd build
make
echo "Сборка завершена"
