# Отчёт к заданию «Переход к ООП, динамические библиотеки»

## 1. Цель работы

Вынести математические вычисления в отдельный объект библиотеки, подключить её сначала как статическую, затем как динамическую, проверить раздельную разработку библиотеки и основной программы и добавить обработку аргументов командной строки.

## 2. Решение

Создана библиотека `mathlib`, содержащая функции `square`, `cube`, `power`, `factorial`. Основная программа `main.cpp` содержит только обработку командной строки и вызовы функций библиотеки.

Структура:

```text
src/
├── main.cpp
├── mathlib.h
└── mathlib.cpp
build_static.sh
build_dynamic.sh
run_examples.sh
```

## 3. Статическая библиотека

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -c src/mathlib.cpp -o build/static/mathlib.o
ar rcs build/static/libmath.a build/static/mathlib.o
g++ -std=c++17 -Wall -Wextra -pedantic -O2 src/main.cpp -I src build/static/libmath.a -o build/static/math_app
```

Запуск:

```bash
./build/static/math_app square 5
```

Результат: `square(5.00) = 25.00`.

## 4. Динамическая библиотека

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -fPIC -c src/mathlib.cpp -o build/dynamic/mathlib.o
g++ -shared -o build/dynamic/libmath.so build/dynamic/mathlib.o
g++ -std=c++17 -Wall -Wextra -pedantic -O2 src/main.cpp -I src -L build/dynamic -lmath -o build/dynamic/math_app
```

Запуск:

```bash
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app square 5
```

Значение переменной `LD_LIBRARY_PATH`: `./build/dynamic`. Она сообщает загрузчику, где искать `libmath.so`.

## 5. Раздельная разработка

При изменении только `src/mathlib.cpp` достаточно пересобрать `libmath.so`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O2 -fPIC -c src/mathlib.cpp -o build/dynamic/mathlib.o
g++ -shared -o build/dynamic/libmath.so build/dynamic/mathlib.o
LD_LIBRARY_PATH=./build/dynamic ./build/dynamic/math_app square 5
```

Повторная компиляция `main.cpp` при изменении только реализации библиотеки не требуется.

## 6. Аргументы командной строки

Используется `int main(int argc, char* argv[])`.

Поддерживаются команды:

```text
math_app square <x>
math_app cube <x>
math_app power <x> <n>
math_app factorial <n>
```

Пример:

```bash
./build/static/math_app power 2 8
```

Результат: `power(2.00, 8) = 256.00`.

## 7. Проверочные результаты

```text
square(5.00) = 25.00
power(2.00, 8) = 256.00
factorial(6) = 720.00
square(5.00) = 25.00
cube(3.00) = 27.00
power(2.00, 10) = 1024.00
factorial(5) = 120.00
```

## 8. Вывод

Математические функции вынесены в отдельную библиотеку. Получены статическая и динамическая версии программы. Проверена возможность раздельной пересборки динамической библиотеки без повторной компиляции основной программы. Реализована обработка `argc` и `argv`, а также показано использование `LD_LIBRARY_PATH`.

## 9. Репозиторий

После создания GitHub-репозитория в отчёт вставляется его ссылка, например:

`https://github.com/<ваш-логин>/oop-dynamic-library`
