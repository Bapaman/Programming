#include <iostream>

class BankAccount {
private:
    double balon;
    std::string accountNumber;

public:
    BankAccount(std::string accNumber) : balon(0.0), accountNumber(accNumber) {}

    double getBalon() const {
        return balon;
    }

    void deposit(double count) {
        if (count > 0) {
            balon += count;
            std::cout << "Счет пополнен на " << count << " рублей. Новый баланс: " << balon << " рублей." << std::endl;
        } else {
            std::cout << "Неверная сумма для пополнения счета." << std::endl;
        }
    }

    void withdraw(double count) {
        if (count > 0 && count <= balon) {
            balon -= count;
            std::cout << "Со счета снято " << count << " рублей. Новый баланс: " << balon << " рублей." << std::endl;
        } else {
            std::cout << "Неверная сумма для снятия или недостаточно средств на счете." << std::endl;
        }
    }
};

int main() {
    BankAccount myAccount("88005553535");

    myAccount.deposit(1000.0);
    myAccount.withdraw(500.0);
    myAccount.withdraw(700.0);

    return 0;
}
