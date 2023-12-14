#include <iostream>
#include <stdexcept>

class Product {
protected:
    double price;
    double weight;

public:
    Product(double p, double w) : price(p), weight(w) {
        if (price <= 0 || weight <= 0) {
            throw std::invalid_argument("Цена и вес должны быть положительными значениями.");
        }
    }

    double getTotalPrice() const {
        return price * weight;
    }
};

class Apple : public Product {
private:
    std::string variety;

public:
    Apple(double p, double w, const std::string& v) : Product(p, w), variety(v) {
        if (variety.empty()) {
            throw std::invalid_argument("Сорт яблока не может быть пустым.");
        }
    }
};

class Orange : public Product {
private:
    std::string origin;

public:
    Orange(double p, double w, const std::string& o) : Product(p, w), origin(o) {
        if (origin.empty()) {
            throw std::invalid_argument("Страна происхождения апельсина не может быть пустой.");
        }
    }
};

int main() {
    try {
        Apple apple(-1.5, 3.0, "Red"); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        Orange orange(2.0, -4.0, "Spain"); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        Apple emptyApple(1.0, 2.5, "");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    try {
        Orange emptyOrange(1.5, 3.0, ""); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
