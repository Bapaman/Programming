#include <iostream>

int main() {
    int число;
    std::cout << "Введите число для вычисления факториала: ";
    std::cin >> число;

    long long факториал = 1;

    for (int i = 1; i <= число; ++i) {
        факториал *= i;
    }

    std::cout << "Факториал " << число << " = " << факториал << std::endl;

    return 0;
}
