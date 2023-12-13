#include <iostream>

int main() {
    int число;
    bool простое = true;

    std::cout << "Введите число для проверки на простоту: ";
    std::cin >> число;

    if (число <= 1) {
        простое = false;
    } else {
        for (int i = 2; i <= число / 2; ++i) {
            if (число % i == 0) {
                простое = false;
                break;
            }
        }
    }

    if (простое) {
        std::cout << число << " - простое число." << std::endl;
    } else {
        std::cout << число << " - не простое число." << std::endl;
    }

    return 0;
}
