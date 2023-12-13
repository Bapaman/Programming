#include <iostream>

int main() {
    double celsius, fahrenheit;
    std::cout << "Введите температуру в цельсиях: ";
    std::cin >> celsius;

    fahrenheit = (celsius * 9/5) + 32;

    std::cout << "Температура в фарингейтах: " << fahrenheit << std::endl;

    return 0;
