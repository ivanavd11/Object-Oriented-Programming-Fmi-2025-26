#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Car
{
private:
    char* brand;
    int year;
    int maxSpeed;

    int* trips;
    int tripsCount;

public:
    // Default constructor
    Car()
    {
        brand = new char[strlen("Unknown") + 1];
        strcpy(brand, "Unknown");

        year = 0;
        maxSpeed = 0;

        trips = nullptr;
        tripsCount = 0;
    }

    // Constructor with parameters
    Car(const char* newBrand,
        int newYear,
        int newMaxSpeed,
        const int* newTrips,
        int count)
    {
        brand = nullptr;
        trips = nullptr;
        tripsCount = 0;
        year = 0;
        maxSpeed = 0;

        // Проверка на марката
        if (newBrand == nullptr || strlen(newBrand) == 0)
        {
            cout << "Invalid brand!" << endl;

            brand = new char[strlen("Unknown") + 1];
            strcpy(brand, "Unknown");
        }
        else
        {
            brand = new char[strlen(newBrand) + 1];
            strcpy(brand, newBrand);
        }

        // Проверка на годината
        if (newYear <= 0)
        {
            cout << "Invalid year!" << endl;
        }
        else
        {
            year = newYear;
        }

        // Проверка на максималната скорост
        if (newMaxSpeed <= 0)
        {
            cout << "Invalid max speed!" << endl;
        }
        else
        {
            maxSpeed = newMaxSpeed;
        }

        // Проверка на броя пътувания
        if (count < 0)
        {
            cout << "Invalid trips count!" << endl;
            tripsCount = 0;
            trips = nullptr;
            return;
        }

        if (count == 0)
        {
            tripsCount = 0;
            trips = nullptr;
            return;
        }

        if (newTrips == nullptr)
        {
            cout << "Invalid trips array!" << endl;
            tripsCount = 0;
            trips = nullptr;
            return;
        }

        tripsCount = count;
        trips = new int[tripsCount];

        for (int i = 0; i < tripsCount; i++)
        {
            if (newTrips[i] < 0)
            {
                cout << "Invalid trip distance!" << endl;
                trips[i] = 0;
            }
            else
            {
                trips[i] = newTrips[i];
            }
        }
    }

    // Destructor
    ~Car()
    {
        delete[] brand;
        delete[] trips;
    }

    // Запис във файл
    bool saveToFile(const char* fileName) const
    {
        if (fileName == nullptr || strlen(fileName) == 0)
        {
            cout << "Invalid file name!" << endl;
            return false;
        }

        ofstream out(fileName);

        if (!out.is_open())
        {
            cout << "Could not open file!" << endl;
            return false;
        }

        out << brand << '\n';
        out << year << '\n';
        out << maxSpeed << '\n';
        out << tripsCount << '\n';

        for (int i = 0; i < tripsCount; i++)
        {
            out << trips[i] << " ";
        }

        out << '\n';

        out.close();
        return true;
    }

    // Четене от файл
    bool readFromFile(const char* fileName)
    {
        if (fileName == nullptr || strlen(fileName) == 0)
        {
            cout << "Invalid file name!" << endl;
            return false;
        }

        ifstream in(fileName);

        if (!in.is_open())
        {
            cout << "Could not open file!" << endl;
            return false;
        }

        char buffer[1000];

        in.getline(buffer, 1000);

        int newYear;
        int newMaxSpeed;
        int newTripsCount;

        in >> newYear;
        in >> newMaxSpeed;
        in >> newTripsCount;

        if (strlen(buffer) == 0)
        {
            cout << "Invalid brand in file!" << endl;
            return false;
        }

        if (newYear <= 0)
        {
            cout << "Invalid year in file!" << endl;
            return false;
        }

        if (newMaxSpeed <= 0)
        {
            cout << "Invalid max speed in file!" << endl;
            return false;
        }

        if (newTripsCount < 0)
        {
            cout << "Invalid trips count in file!" << endl;
            return false;
        }

        int* newTrips = nullptr;

        if (newTripsCount > 0)
        {
            newTrips = new int[newTripsCount];

            for (int i = 0; i < newTripsCount; i++)
            {
                in >> newTrips[i];

                if (!in || newTrips[i] < 0)
                {
                    cout << "Invalid trip data in file!" << endl;
                    delete[] newTrips;
                    return false;
                }
            }
        }

        // Едва след като всичко е валидно,
        // заменяме старите данни.
        delete[] brand;
        delete[] trips;

        brand = new char[strlen(buffer) + 1];
        strcpy(brand, buffer);

        year = newYear;
        maxSpeed = newMaxSpeed;

        tripsCount = newTripsCount;
        trips = newTrips;

        in.close();

        return true;
    }

    int getTotalKilometers() const
    {
        int sum = 0;

        for (int i = 0; i < tripsCount; i++)
        {
            sum += trips[i];
        }

        return sum;
    }

    int getLongestTrip() const
    {
        if (tripsCount == 0)
        {
            return 0;
        }

        int maximum = trips[0];

        for (int i = 1; i < tripsCount; i++)
        {
            if (trips[i] > maximum)
            {
                maximum = trips[i];
            }
        }

        return maximum;
    }

    void print() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
        cout << "Max speed: " << maxSpeed << endl;

        cout << "Trips: ";

        for (int i = 0; i < tripsCount; i++)
        {
            cout << trips[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int trips[] = { 120, 350, 90, 500 };

    Car car("BMW", 2022, 250, trips, 4);

    car.print();

    cout << "Total kilometers: "
        << car.getTotalKilometers() << endl;

    cout << "Longest trip: "
        << car.getLongestTrip() << endl;

    car.saveToFile("car.txt");

    Car secondCar;

    if (secondCar.readFromFile("car.txt"))
    {
        secondCar.print();
    }

    return 0;
}