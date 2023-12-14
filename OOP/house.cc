#include <iostream>
#include <string>

class House {
public:
    House(int roomCount, const std::string& address) : roomCount(roomCount), address(address) {}

    int getRoomCount() const {
        return roomCount;
    }

    const std::string& getAddress() const {
        return address;
    }

private:
    int roomCount;
    std::string address;
};

class Person {
public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    const std::string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

private:
    std::string name;
    int age;
};

class Resident : public Person {
public:
    Resident(const std::string& name, int age) : Person(name, age), house(nullptr) {}

    void linkHouse(House* newHouse) {
        house = newHouse;
    }

    const House* getHouse() const {
        return house;
    }

private:
    House* house;
};

int main() {
    House myHouse(3, "ул. Боржуазная 124");
    Resident resident("Slavi4 Vyacheslavi4", 30);

    resident.linkHouse(&myHouse);

    // Accessing variables for testing
    std::cout << "Человек: " << resident.getName() << ", Возраст: " << resident.getAge() << std::endl;
    std::cout << "Дом: " << resident.getHouse()->getAddress() << ", Колличество комнат: " << resident.getHouse()->getRoomCount() << std::endl;

    return 0;
}
