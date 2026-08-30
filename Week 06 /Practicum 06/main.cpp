#include <iostream>
#include "Temperature.h"

using namespace std;

int main()
{
    Temperature t1(0, 'c');
    Temperature t2(32, 'f');

    cout << (t1 == t2) << endl;   // 1

    Temperature t3(20, 'c');
    Temperature t4(68, 'f');

    cout << (t3 == t4) << endl;   // 1
    cout << (t3 < t4) << endl;    // 0

    Temperature sum = t3 + t4;

    cout << sum.getTemperature()
        << " "
        << sum.getSystem()
        << endl;

    t3 += t4;

    cout << t3.getTemperature()
        << " "
        << t3.getSystem()
        << endl;

    return 0;
}