#include <iostream>
#include <string>

// Базовый класс "Фрукт"
class Fruit {
public:
    virtual void getVitamins() const {
        std::cout << "Этот фрукт содержит витамины." << std::endl;
    }
};

// Подкласс "Яблоко"
class Apple : public Fruit {
public:
    void getVitamins() const override {
        std::cout << "Яблоко содержит витамин C." << std::endl;
    }
};

// Подкласс "Апельсин"
class Orange : public Fruit {
public:
    void getVitamins() const override {
        std::cout << "Апельсин содержит витамин C и витамин A." << std::endl;
    }
};

// Базовый класс "Транспортное Средство"
class TransportVehicle {
protected:
    double speed;
    std::string type;

public:
    TransportVehicle(double s, const std::string& t) : speed(s), type(t) {}

    virtual void displayInfo() const {
        std::cout << "Тип: " << type << ", Скорость: " << speed << " км/ч" << std::endl;
    }
};

// Подкласс "Автомобиль"
class Car : public TransportVehicle {
private:
    int numberOfSeats;

public:
    Car(double s, const std::string& t, int seats) : TransportVehicle(s, t), numberOfSeats(seats) {}

    void displayInfo() const override {
        TransportVehicle::displayInfo();
        std::cout << "Количество мест: " << numberOfSeats << std::endl;
    }
};

// Подкласс "Велосипед"
class Bicycle : public TransportVehicle {
private:
    bool hasBasket;

public:
    Bicycle(double s, const std::string& t, bool basket) : TransportVehicle(s, t), hasBasket(basket) {}

    void displayInfo() const override {
        TransportVehicle::displayInfo();
        if (hasBasket) {
            std::cout << "Велосипед имеет корзину." << std::endl;
        } else {
            std::cout << "Велосипед не имеет корзины." << std::endl;
        }
    }
};

int main() {
    // Примеры работы с классом "Фрукт"
    Fruit frukti;
    frukti.getVitamins();

    Apple yabloko;
    yabloko.getVitamins();

    Orange apelsin;
    apelsin.getVitamins();

    std::cout << std::endl;

    // Примеры работы с классом "Транспортное Средство"
    Car mashina(120.5, "Автомобиль", 4);
    mashina.displayInfo();

    Bicycle velosiped(25.0, "Велосипед", true);
    velosiped.displayInfo();

    return 0;
}
