#include <iostream>

int main() {
    int год;
    bool високосный = false;

    std::cout << "Введите год для проверки на високосность: ";
    std::cin >> год;

    if ((год % 4 == 0 && год % 100 != 0) || (год % 400 == 0)) {
        високосный = true;
    }

    if (високосный) {
        std::cout << год << " - високосный год." << std::endl;
    } else {
        std::cout << год << " - не високосный год." << std::endl;
    }

    return 0;
}
