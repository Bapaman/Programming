#include <iostream>
#include <cmath>
#include <stdexcept>

class Figure {
public:
    virtual double calculateArea() const = 0;
    virtual ~Figure() {}
};

class Rectangle : public Figure {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {
        if (length <= 0 || width <= 0) {
            throw std::invalid_argument("1");
        }
    }

    double calculateArea() const override {
        return length * width;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {
        if (radius <= 0) {
            throw std::invalid_argument("1");
        }
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    const int size = 3;
    Figure* figures[size];

    try {
        figures[0] = new Rectangle(3, 4);
        figures[1] = new Circle(2);
        figures[2] = new Rectangle(1, 5);  // This will throw an exception

        for (int i = 0; i < size; ++i) {
            double area = figures[i]->calculateArea();
            std::cout << "Площадь фигуры " << i + 1 << ": " << area << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        if (e.what() == std::string("1")) {
            std::cerr << "Ошибка: Фигура с отрицательными сторонами." << std::endl;
        } else {
            std::cerr << "Неизвестная ошибка." << std::endl;
        }
    }

    for (int i = 0; i < size; ++i) {
        delete figures[i];
    }

    return 0;
}
