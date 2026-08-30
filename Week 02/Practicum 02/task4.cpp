#include <iostream>

using namespace std;

class Counter
{
private:
    int value;
    mutable int accessCount;

public:
    // Конструктор
    Counter(int val = 0)
    {
        value = val;
        accessCount = 0;
    }

    // Увеличава value
    void increment()
    {
        value++;
    }

    // Връща value и увеличава accessCount
    int getValue() const
    {
        accessCount++;
        return value;
    }

    // Връща броя на извикванията
    int getAccessCount() const
    {
        return accessCount;
    }
};

int main()
{
    Counter c;

    c.increment();
    c.increment();

    cout << c.getValue() << endl;        // 2
    cout << c.getValue() << endl;        // 2
    cout << c.getAccessCount() << endl;  // 2

    return 0;
}