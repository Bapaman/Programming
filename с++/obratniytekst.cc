#include <iostream>
#include <string>

int main() {
    std::string строка;
    std::cout << "Введите строку для отражения: ";
    std::cin >> строка;

    if (!строка.empty()) {
        char последнийСимвол = строка.back();
        строка.pop_back();
        строка = последнийСимвол + строка;

        std::cout << "Отраженная строка: " << строка << std::endl;
    } else {
        std::cout << "Строка пуста." << std::endl;
    }

    return 0;
}
