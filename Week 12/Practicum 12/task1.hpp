#include <iostream>
#include <cmath>
#include <concepts>

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

template<typename T>
bool isEqual(const T& a, const T& b)
{
	return a == b;
}

template<>
bool isEqual<double>(const double& a, const double& b)
{
	constexpr double EPSILON = 0.000001;

	return std::abs(a - b) < EPSILON;
}

// 3. Concept за типове, които могат да се извеждат
template <typename T>
concept Printable = requires(std::ostream & output,const T & value) 
{
        { output << value } -> std::same_as<std::ostream&>;
};

// Функцията приема само Printable типове
template <Printable T>
void printArr(const T* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i];

        if (i + 1 < size) {
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}

int main() {
    // Тестване на mySwap
    int first = 10;
    int second = 20;

    std::cout << "Before swap: "
        << first << ' ' << second << '\n';

    mySwap(first, second);

    std::cout << "After swap: "
        << first << ' ' << second << '\n';

    std::string firstName = "Ivan";
    std::string secondName = "Maria";

    mySwap(firstName, secondName);

    std::cout << firstName << ' '
        << secondName << '\n';

    // Тестване на isEqual
    std::cout << std::boolalpha;

    std::cout << "10 == 10: "
        << isEqual(10, 10) << '\n';

    std::cout << "10 == 20: "
        << isEqual(10, 20) << '\n';

    double a = 0.1 + 0.2;
    double b = 0.3;

    std::cout << "0.1 + 0.2 == 0.3: "
        << isEqual(a, b) << '\n';

    // Тестване на printArr
    int numbers[] = { 1, 2, 3, 4, 5 };

    std::string names[] = {
        "Ivan",
        "Maria",
        "Georgi"
    };

    double values[] = { 1.25, 2.50, 3.75 };

    printArr(numbers, 5);
    printArr(names, 3);
    printArr(values, 3);

    return 0;
}