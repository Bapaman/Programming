#include <iostream>

class Figure {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle : public Figure {
private:
    double storona1;
    double storona2;

public:
    Rectangle(double s1, double s2) : storona1(s1), storona2(s2) {}

    virtual double calculateArea() const override {
        return storona1 * storona2;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    virtual double calculateArea() const override {
        return 3.14159265358979323846 * radius * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    std::cout << "Площадь прямоугольника: " << rectangle.calculateArea() << std::endl;
    std::cout << "Площадь круга: " << circle.calculateArea() << std::endl;

    return 0;
}
