#include <iostream>
#include <iomanip>
#include <string>
#include "mathlib.h"

void printUsage(const char* program) {
    std::cout << "Использование:\n"
              << "  " << program << " square <x>\n"
              << "  " << program << " cube <x>\n"
              << "  " << program << " power <x> <n>\n"
              << "  " << program << " factorial <n>\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) { printUsage(argv[0]); return 1; }
    std::string operation = argv[1];
    std::cout << std::fixed << std::setprecision(2);
    try {
        if (operation == "square" && argc == 3) {
            double x = std::stod(argv[2]);
            std::cout << "square(" << x << ") = " << square(x) << '\n';
        } else if (operation == "cube" && argc == 3) {
            double x = std::stod(argv[2]);
            std::cout << "cube(" << x << ") = " << cube(x) << '\n';
        } else if (operation == "power" && argc == 4) {
            double x = std::stod(argv[2]); int n = std::stoi(argv[3]);
            std::cout << "power(" << x << ", " << n << ") = " << power(x, n) << '\n';
        } else if (operation == "factorial" && argc == 3) {
            int n = std::stoi(argv[2]);
            if (n < 0) { std::cerr << "Ошибка: n должно быть неотрицательным.\n"; return 2; }
            std::cout << "factorial(" << n << ") = " << factorial(n) << '\n';
        } else {
            std::cerr << "Ошибка: неверные аргументы.\n"; printUsage(argv[0]); return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка преобразования аргументов: " << e.what() << '\n'; return 2;
    }
    return 0;
}
