#include <iostream>

int main() {
    int число;
    std::cout << "Введите число для таблицы умножения: ";
    std::cin >> число;

    std::cout << "Таблица умножения для " << число << ":" << std::endl;
    
    for (int i = 1; i <= 10; ++i) {
        std::cout << число << " * " << i << " = " << число * i << std::endl;
    }

    return 0;
}
