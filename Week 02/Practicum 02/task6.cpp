#include <iostream>

using namespace std;

class Point2D
{
private:
    double x;
    double y;

public:
    // Default конструктор
    Point2D()
    {
        x = 0;
        y = 0;
    }

    // Конструктор с параметри
    Point2D(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    // Деструктор
    ~Point2D()
    {
        // Няма динамична памет, така че е празен.
    }

    // Извеждане
    void print() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Point2D p1;
    Point2D p2(3.5, 7.2);

    p1.print();
    p2.print();

    return 0;
}