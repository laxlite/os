SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE}")" && pwd)" # определяем абсолютный путь к скрипту
echo "build-linux-release.sh located in: ${SCRIPT_DIR}"

cd $SCRIPT_DIR
if [ -d "build-linux-release" ]; then
    rm -rf "build-linux-release"
fi
mkdir build-linux-release
cmake -S . -B build-linux-release -DCMAKE_BUILD_TYPE=Release

echo "=== cmake end ==="

cd build-linux-release
make
echo "build-linux-release was completed"