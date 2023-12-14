#include <iostream>
#include <string>

class Dog {
public:
    std::string name;
    int age;

    Dog(std::string n, int a) : name(n), age(a) {}

    void displayInfo() {
        std::cout << "Имя: " << name << ", Возраст: " << age << " лет" << std::endl;
    }
};

int main() {
    Dog dog1("Шерлок", 3);
    Dog dog2("Ватсон", 5);
    Dog dog3("Мориарти", 2);

    std::cout << "Информация о собаках:" << std::endl;
    dog1.displayInfo();
    dog2.displayInfo();
    dog3.displayInfo();

    return 0;
}
