#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


// ======================================================
// BALLOON
// ======================================================

enum class Color
{
    White,
    Green,
    Red
};

class Balloon
{
private:
    double price;
    Color color;

public:
    Balloon()
    {
        price = 0;
        color = Color::White;
    }

    Balloon(double newPrice, Color newColor)
    {
        price = 0;
        color = Color::White;

        setPrice(newPrice);
        setColor(newColor);
    }

    void setPrice(double newPrice)
    {
        if (newPrice < 0)
        {
            cout << "Invalid balloon price!" << endl;
            return;
        }

        price = newPrice;
    }

    void setColor(Color newColor)
    {
        color = newColor;
    }

    double getPrice() const
    {
        return price;
    }

    Color getColor() const
    {
        return color;
    }
};


// ======================================================
// NARGA
// ======================================================

enum class Flavor
{
    Blueberry,
    Queen,
    Mango,
    Mint,
    Apple
};

class Narga
{
private:
    double price;
    char brand[1025];
    Flavor flavor;

public:
    Narga()
    {
        price = 0;
        strcpy(brand, "Unknown");
        flavor = Flavor::Blueberry;
    }

    Narga(double newPrice,
        const char* newBrand,
        Flavor newFlavor)
    {
        price = 0;
        strcpy(brand, "Unknown");
        flavor = Flavor::Blueberry;

        setPrice(newPrice);
        setBrand(newBrand);
        setFlavor(newFlavor);
    }

    void setPrice(double newPrice)
    {
        if (newPrice < 0)
        {
            cout << "Invalid narga price!" << endl;
            return;
        }

        price = newPrice;
    }

    void setBrand(const char* newBrand)
    {
        if (newBrand == nullptr ||
            strlen(newBrand) == 0 ||
            strlen(newBrand) > 1024)
        {
            cout << "Invalid brand!" << endl;
            return;
        }

        strcpy(brand, newBrand);
    }

    void setFlavor(Flavor newFlavor)
    {
        flavor = newFlavor;
    }

    double getPrice() const
    {
        return price;
    }

    const char* getBrand() const
    {
        return brand;
    }

    Flavor getFlavor() const
    {
        return flavor;
    }
};


// ======================================================
// ALCOHOL
// ======================================================

class Alcohol
{
private:
    char name[129];
    double price;

public:
    Alcohol()
    {
        strcpy(name, "Unknown");
        price = 0;
    }

    Alcohol(const char* newName, double newPrice)
    {
        strcpy(name, "Unknown");
        price = 0;

        setName(newName);
        setPrice(newPrice);
    }

    void setName(const char* newName)
    {
        if (newName == nullptr ||
            strlen(newName) == 0 ||
            strlen(newName) > 128)
        {
            cout << "Invalid alcohol name!" << endl;
            return;
        }

        strcpy(name, newName);
    }

    void setPrice(double newPrice)
    {
        if (newPrice < 0)
        {
            cout << "Invalid alcohol price!" << endl;
            return;
        }

        price = newPrice;
    }

    const char* getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }
};


// ======================================================
// CLIENT
// ======================================================

struct Client
{
private:
    char* name;
    char* billFile;

    void copyFrom(const Client& other)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        billFile = new char[strlen(other.billFile) + 1];
        strcpy(billFile, other.billFile);
    }

    void freeMemory()
    {
        delete[] name;
        delete[] billFile;
    }

public:
    Client()
    {
        name = new char[strlen("Unknown") + 1];
        strcpy(name, "Unknown");

        billFile = new char[strlen("no_file") + 1];
        strcpy(billFile, "no_file");
    }

    Client(const char* newName, const char* newBillFile)
    {
        name = nullptr;
        billFile = nullptr;

        setName(newName);
        setBillFile(newBillFile);
    }

    Client(const Client& other)
    {
        copyFrom(other);
    }

    Client& operator=(const Client& other)
    {
        if (this != &other)
        {
            freeMemory();
            copyFrom(other);
        }

        return *this;
    }

    ~Client()
    {
        freeMemory();
    }

    void setName(const char* newName)
    {
        if (newName == nullptr || strlen(newName) == 0)
        {
            cout << "Invalid client name!" << endl;

            newName = "Unknown";
        }

        delete[] name;

        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    void setBillFile(const char* newFile)
    {
        if (newFile == nullptr || strlen(newFile) == 0)
        {
            cout << "Invalid bill file!" << endl;

            newFile = "no_file";
        }

        delete[] billFile;

        billFile = new char[strlen(newFile) + 1];
        strcpy(billFile, newFile);
    }

    const char* getName() const
    {
        return name;
    }

    const char* getBillFile() const
    {
        return billFile;
    }
};


// ======================================================
// NIGHT CLUB
// ======================================================

class NightClub
{
private:

    struct BalloonItem
    {
        Balloon item;
        int count;
    };

    struct NargaItem
    {
        Narga item;
        int count;
    };

    struct AlcoholItem
    {
        Alcohol item;
        int count;
    };


    BalloonItem balloons[1024];
    AlcoholItem alcohols[512];
    NargaItem nargas[256];

    int balloonTypes;
    int alcoholTypes;
    int nargaTypes;

    int totalBalloons;
    int totalAlcohols;
    int totalNargas;


    // --------------------------------------------------
    // Помощни функции
    // --------------------------------------------------

    Color stringToColor(const string& str) const
    {
        if (str == "white")
            return Color::White;

        if (str == "green")
            return Color::Green;

        return Color::Red;
    }


    bool validColor(const string& str) const
    {
        return str == "white" ||
            str == "green" ||
            str == "red";
    }


    Flavor stringToFlavor(const string& str) const
    {
        if (str == "blueberry")
            return Flavor::Blueberry;

        if (str == "queen")
            return Flavor::Queen;

        if (str == "mango")
            return Flavor::Mango;

        if (str == "mint")
            return Flavor::Mint;

        return Flavor::Apple;
    }


    bool validFlavor(const string& str) const
    {
        return str == "blueberry" ||
            str == "queen" ||
            str == "mango" ||
            str == "mint" ||
            str == "apple";
    }


    int findBalloon(Color color) const
    {
        for (int i = 0; i < balloonTypes; i++)
        {
            if (balloons[i].item.getColor() == color)
            {
                return i;
            }
        }

        return -1;
    }


    int findAlcohol(const char* name) const
    {
        for (int i = 0; i < alcoholTypes; i++)
        {
            if (strcmp(alcohols[i].item.getName(), name) == 0)
            {
                return i;
            }
        }

        return -1;
    }


    int findNarga(const char* brand, Flavor flavor) const
    {
        for (int i = 0; i < nargaTypes; i++)
        {
            if (strcmp(nargas[i].item.getBrand(), brand) == 0 &&
                nargas[i].item.getFlavor() == flavor)
            {
                return i;
            }
        }

        return -1;
    }


public:

    // ==================================================
    // Constructor
    // ==================================================

    NightClub()
    {
        balloonTypes = 0;
        alcoholTypes = 0;
        nargaTypes = 0;

        totalBalloons = 0;
        totalAlcohols = 0;
        totalNargas = 0;
    }


    // ==================================================
    // ADD BALLOON
    // файл:
    //
    // green-25.6
    // ==================================================

    bool addBalloon(const char* fileName)
    {
        if (totalBalloons >= 1024)
        {
            cout << "Balloon storage is full!" << endl;
            return false;
        }

        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Cannot open file!" << endl;
            return false;
        }

        string line;
        getline(file, line);

        file.close();

        size_t separator = line.find('-');

        if (separator == string::npos)
        {
            cout << "Invalid balloon file!" << endl;
            return false;
        }

        string colorStr = line.substr(0, separator);
        string priceStr = line.substr(separator + 1);

        if (!validColor(colorStr))
        {
            cout << "Invalid balloon color!" << endl;
            return false;
        }

        double price;

        try
        {
            price = stod(priceStr);
        }
        catch (...)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        if (price < 0)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        Color color = stringToColor(colorStr);

        int index = findBalloon(color);

        if (index != -1)
        {
            balloons[index].count++;
        }
        else
        {
            balloons[balloonTypes].item =
                Balloon(price, color);

            balloons[balloonTypes].count = 1;

            balloonTypes++;
        }

        totalBalloons++;

        return true;
    }


    // ==================================================
    // ADD ALCOHOL
    //
    // black_label-60
    // ==================================================

    bool addAlcohol(const char* fileName)
    {
        if (totalAlcohols >= 512)
        {
            cout << "Alcohol storage is full!" << endl;
            return false;
        }

        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Cannot open file!" << endl;
            return false;
        }

        string line;
        getline(file, line);

        file.close();

        size_t separator = line.find('-');

        if (separator == string::npos)
        {
            cout << "Invalid alcohol file!" << endl;
            return false;
        }

        string name = line.substr(0, separator);
        string priceStr = line.substr(separator + 1);

        if (name.empty() || name.size() > 128)
        {
            cout << "Invalid alcohol name!" << endl;
            return false;
        }

        double price;

        try
        {
            price = stod(priceStr);
        }
        catch (...)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        if (price < 0)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        int index = findAlcohol(name.c_str());

        if (index != -1)
        {
            alcohols[index].count++;
        }
        else
        {
            alcohols[alcoholTypes].item =
                Alcohol(name.c_str(), price);

            alcohols[alcoholTypes].count = 1;

            alcoholTypes++;
        }

        totalAlcohols++;

        return true;
    }


    // ==================================================
    // ADD NARGA
    //
    // OS-queen-30
    // ==================================================

    bool addNarga(const char* fileName)
    {
        if (totalNargas >= 256)
        {
            cout << "Narga storage is full!" << endl;
            return false;
        }

        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Cannot open file!" << endl;
            return false;
        }

        string line;
        getline(file, line);

        file.close();

        size_t first = line.find('-');
        size_t second = line.find('-', first + 1);

        if (first == string::npos ||
            second == string::npos)
        {
            cout << "Invalid narga file!" << endl;
            return false;
        }

        string brand = line.substr(0, first);
        string flavorStr =
            line.substr(first + 1, second - first - 1);

        string priceStr =
            line.substr(second + 1);

        if (brand.empty() || brand.size() > 1024)
        {
            cout << "Invalid brand!" << endl;
            return false;
        }

        if (!validFlavor(flavorStr))
        {
            cout << "Invalid flavor!" << endl;
            return false;
        }

        double price;

        try
        {
            price = stod(priceStr);
        }
        catch (...)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        if (price < 0)
        {
            cout << "Invalid price!" << endl;
            return false;
        }

        Flavor flavor = stringToFlavor(flavorStr);

        int index =
            findNarga(brand.c_str(), flavor);

        if (index != -1)
        {
            nargas[index].count++;
        }
        else
        {
            nargas[nargaTypes].item =
                Narga(price, brand.c_str(), flavor);

            nargas[nargaTypes].count = 1;

            nargaTypes++;
        }

        totalNargas++;

        return true;
    }


    // ==================================================
    // REMOVE BALLOON
    // ==================================================

    bool removeBalloon(Color color)
    {
        int index = findBalloon(color);

        if (index == -1 ||
            balloons[index].count == 0)
        {
            cout << "Balloon not found!" << endl;
            return false;
        }

        balloons[index].count--;
        totalBalloons--;

        return true;
    }


    // ==================================================
    // REMOVE ALCOHOL
    // ==================================================

    bool removeAlcohol(const char* name)
    {
        int index = findAlcohol(name);

        if (index == -1 ||
            alcohols[index].count == 0)
        {
            cout << "Alcohol not found!" << endl;
            return false;
        }

        alcohols[index].count--;
        totalAlcohols--;

        return true;
    }


    // ==================================================
    // REMOVE NARGA
    // ==================================================

    bool removeNarga(const char* brand, Flavor flavor)
    {
        int index = findNarga(brand, flavor);

        if (index == -1 ||
            nargas[index].count == 0)
        {
            cout << "Narga not found!" << endl;
            return false;
        }

        nargas[index].count--;
        totalNargas--;

        return true;
    }


    // ==================================================
    // CHECK METHODS
    // ==================================================

    bool hasBalloon(Color color) const
    {
        int index = findBalloon(color);

        return index != -1 &&
            balloons[index].count > 0;
    }


    bool hasAlcohol(const char* name) const
    {
        int index = findAlcohol(name);

        return index != -1 &&
            alcohols[index].count > 0;
    }


    bool hasNarga(Flavor flavor) const
    {
        for (int i = 0; i < nargaTypes; i++)
        {
            if (nargas[i].item.getFlavor() == flavor &&
                nargas[i].count > 0)
            {
                return true;
            }
        }

        return false;
    }


    // ==================================================
    // BILL
    // ==================================================

    double calculateBill(const char* fileName) const
    {
        ifstream file(fileName);

        if (!file.is_open())
        {
            cout << "Cannot open bill file!" << endl;
            return -1;
        }

        enum class Section
        {
            None,
            Alcohol,
            Balloon,
            Narga
        };

        Section section = Section::None;

        double total = 0;

        string line;

        while (getline(file, line))
        {
            if (line.empty())
                continue;


            if (line == "Alchohols:" ||
                line == "Alcohols:")
            {
                section = Section::Alcohol;
                continue;
            }


            if (line == "Baloons:" ||
                line == "Balloons:")
            {
                section = Section::Balloon;
                continue;
            }


            if (line == "Narga:" ||
                line == "Nargas:")
            {
                section = Section::Narga;
                continue;
            }


            // ------------------------------------------
            // ALCOHOL
            // name-count
            // ------------------------------------------

            if (section == Section::Alcohol)
            {
                size_t separator = line.find('-');

                if (separator == string::npos)
                    continue;

                string name =
                    line.substr(0, separator);

                int count;

                try
                {
                    count =
                        stoi(line.substr(separator + 1));
                }
                catch (...)
                {
                    continue;
                }

                if (count <= 0)
                    continue;

                int index =
                    findAlcohol(name.c_str());

                if (index != -1 &&
                    alcohols[index].count >= count)
                {
                    total +=
                        alcohols[index].item.getPrice()
                        * count;
                }
                else
                {
                    cout << "Alcohol unavailable: "
                        << name << endl;

                    file.close();
                    return -1;
                }
            }


            // ------------------------------------------
            // BALLOON
            // color-count
            // ------------------------------------------

            else if (section == Section::Balloon)
            {
                size_t separator = line.find('-');

                if (separator == string::npos)
                    continue;

                string colorStr =
                    line.substr(0, separator);

                if (!validColor(colorStr))
                    continue;

                int count;

                try
                {
                    count =
                        stoi(line.substr(separator + 1));
                }
                catch (...)
                {
                    continue;
                }

                if (count <= 0)
                    continue;

                Color color =
                    stringToColor(colorStr);

                int index =
                    findBalloon(color);

                if (index != -1 &&
                    balloons[index].count >= count)
                {
                    total +=
                        balloons[index].item.getPrice()
                        * count;
                }
                else
                {
                    cout << "Balloon unavailable!"
                        << endl;

                    file.close();
                    return -1;
                }
            }


            // ------------------------------------------
            // NARGA
            // brand-flavor-count
            // ------------------------------------------

            else if (section == Section::Narga)
            {
                size_t first = line.find('-');
                size_t second =
                    line.find('-', first + 1);

                if (first == string::npos ||
                    second == string::npos)
                {
                    continue;
                }

                string brand =
                    line.substr(0, first);

                string flavorStr =
                    line.substr(
                        first + 1,
                        second - first - 1
                    );

                if (!validFlavor(flavorStr))
                    continue;

                int count;

                try
                {
                    count =
                        stoi(line.substr(second + 1));
                }
                catch (...)
                {
                    continue;
                }

                if (count <= 0)
                    continue;

                Flavor flavor =
                    stringToFlavor(flavorStr);

                int index =
                    findNarga(
                        brand.c_str(),
                        flavor
                    );

                if (index != -1 &&
                    nargas[index].count >= count)
                {
                    total +=
                        nargas[index].item.getPrice()
                        * count;
                }
                else
                {
                    cout << "Narga unavailable!"
                        << endl;

                    file.close();
                    return -1;
                }
            }
        }

        file.close();

        return total;
    }


    // ==================================================
    // DAILY PROFIT
    //
    // записва:
    // length
    // name
    // amount
    //
    // в money.dat
    // ==================================================

    double dailyProfit(Client* clients,
        int clientsCount) const
    {
        if (clients == nullptr ||
            clientsCount < 0)
        {
            cout << "Invalid clients!" << endl;
            return 0;
        }

        ofstream out(
            "money.dat",
            ios::binary
        );

        if (!out.is_open())
        {
            cout << "Cannot create money.dat!"
                << endl;

            return 0;
        }

        double profit = 0;

        for (int i = 0;
            i < clientsCount;
            i++)
        {
            double amount =
                calculateBill(
                    clients[i].getBillFile()
                );

            if (amount < 0)
            {
                cout << "Invalid bill for "
                    << clients[i].getName()
                    << endl;

                continue;
            }

            profit += amount;

            int nameLength =
                strlen(clients[i].getName());

            out.write(
                reinterpret_cast<const char*>(
                    &nameLength
                    ),
                sizeof(nameLength)
            );

            out.write(
                clients[i].getName(),
                nameLength
            );

            out.write(
                reinterpret_cast<const char*>(
                    &amount
                    ),
                sizeof(amount)
            );
        }

        out.close();

        return profit;
    }
};
