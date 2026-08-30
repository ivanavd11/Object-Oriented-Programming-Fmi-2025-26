#include <iostream>
using namespace std;
class Car
{
private:
    char brand[41];
    double fuel;
    double fuelCapacity;

public:
    // Конструктор
    Car(const char* carBrand = "", double currentFuel = 0, double capacity = 50)
    {
        strcpy(brand, carBrand);

        if (currentFuel >= 0)
        {
            fuel = currentFuel;
        }
        else
        {
            fuel = 0;
        }

        if (capacity > 0)
        {
            fuelCapacity = capacity;
        }
        else
        {
            fuelCapacity = 50;
        }
    }

    // Зареждане
    void refuel(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid amount!" << endl;
            return;
        }

        if (fuel + amount > fuelCapacity)
        {
            cout << "Fuel capacity exceeded!" << endl;
            return;
        }

        fuel += amount;
    }

    // Каране
    void drive(double km)
    {
        double neededFuel = km * 0.1;

        if (neededFuel > fuel)
        {
            cout << "Not enough fuel!" << endl;
            return;
        }

        fuel -= neededFuel;
    }

    // Getter за горивото
    double getFuel() const
    {
        return fuel;
    }

    // Getter за марката
    const char* getBrand() const
    {
        return brand;
    }
};

int main()
{
    Car car("BMW", 20, 60);

    car.refuel(15);

    car.drive(100);

    cout << "Brand: " << car.getBrand() << endl;
    cout << "Fuel: " << car.getFuel() << endl;

    car.drive(500);

    car.refuel(100);

    return 0;
}