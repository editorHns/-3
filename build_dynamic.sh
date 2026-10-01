#!/bin/bash
set -e
mkdir -p build/dynamic
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -fPIC -c src/mathlib.cpp -o build/dynamic/mathlib.o
g++ -shared -o build/dynamic/libmath.so build/dynamic/mathlib.o
g++ -std=c++17 -Wall -Wextra -pedantic -O2 src/main.cpp -I src -L build/dynamic -lmath -o build/dynamic/math_app
echo "Динамическая сборка завершена."
