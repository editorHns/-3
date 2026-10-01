#!/bin/bash
set -e
./build/static/math_app square 5
./build/static/math_app power 2 8
./build/static/math_app factorial 6
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app square 5
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app cube 3
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app power 2 10
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app factorial 5
