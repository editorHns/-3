#!/bin/bash
set -e
mkdir -p build/static
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -c src/mathlib.cpp -o build/static/mathlib.o
ar rcs build/static/libmath.a build/static/mathlib.o
g++ -std=c++17 -Wall -Wextra -pedantic -O2 src/main.cpp -I src build/static/libmath.a -o build/static/math_app
echo "Статическая сборка завершена."
