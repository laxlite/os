SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)" # определяем абсолютный путь к скрипту
echo "build.sh located in: ${SCRIPT_DIR}"

cd $SCRIPT_DIR
cd ..

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
