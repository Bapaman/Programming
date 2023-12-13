#include <iostream>
#include <string>

int main() {
    std::string строка;
    std::cout << "Введите строку для подсчета гласных: ";
    std::getline(std::cin, строка);

    int количествоГласных = 0;

    for (char символ : строка) {
        char a = tolower(символ);
        if (a == 'а' || a == 'е' || a == 'ё' ||
            a == 'и' || a == 'о' || a == 'у' ||
            a == 'ы' || a == 'э' || a == 'ю' ||
            a == 'я' || a == 'a' || a == 'e' ||
            a == 'i' || a == 'o' || a == 'u') {
            количествоГласных++;
        }
    }

    std::cout << "Количество гласных в строке: " << количествоГласных << std::endl;

    return 0;
}
