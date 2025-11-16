SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)" # определяем абсолютный путь к скрипту
echo "build-linux-debug.sh located in: ${SCRIPT_DIR}"

cd $SCRIPT_DIR
if [ -d "build-linux-debug" ]; then
    rm -rf "build-linux-debug"
fi
mkdir build-linux-debug
cmake -S . -B build-linux-debug -DCMAKE_BUILD_TYPE=Debug

echo "=== cmake end ==="

cd build-linux-debug
make
echo "build-linux-debug was completed"