set -e

python3.7 pack.py

cd cpp
mkdir build 2>&1 >/dev/null || true
cd build
cmake ..
make
cp ../bin/tfnative ../../dist/tfnative

echo "build done!"