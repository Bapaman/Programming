#include <iostream>
int main() {
    int число1, число2;
    std::cout << "Введите первое число: ";
    std::cin >> число1;
    std::cout << "Введите второе число: ";
    std::cin >> число2;
    int сумма = число1 + число2;
    std::cout << "Сумма чисел: " << сумма << std::endl;
    return 0;
}
