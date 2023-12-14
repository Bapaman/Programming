#include <iostream>
#include <cmath>

class Figura {
public:
    virtual double raschitatPloshchad() const = 0;
    virtual ~Figura() {}
};

class Pryamougolnik : public Figura {
private:
    double dlinna;
    double shirina;

public:
    Pryamougolnik(double l, double w) : dlinna(l), shirina(w) {}
    
    double raschitatPloshchad() const override {
        return dlinna * shirina;
    }
};

class Krug : public Figura {
private:
    double radius;

public:
    Krug(double r) : radius(r) {}
    
    double raschitatPloshchad() const override {
        return M_PI * radius * radius;
    }
};

int main() {
    const int razmerMassiva = 3;
    Figura* figury[razmerMassiva];

    figury[0] = new Pryamougolnik(3.0, 4.0);
    figury[1] = new Krug(2.5);
    figury[2] = new Pryamougolnik(5.0, 2.0);

    for (int i = 0; i < razmerMassiva; ++i) {
        std::cout << "Ploshchad figury " << i + 1 << ": " << figury[i]->raschitatPloshchad() << std::endl;
    }

    // Osobo udalyayem vydelennoye pamyat'
    for (int i = 0; i < razmerMassiva; ++i) {
        delete figury[i];
    }

    return 0;
}
