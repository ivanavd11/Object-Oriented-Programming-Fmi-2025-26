#include <exception>
#include <iostream>
#include <stdexcept>

#include "NumericPair.hpp"

int main() {
    try {
        NumericPair<double> p(0.0, 0.0);

        p.setFirst(10.5);
        p.setSecond(-3.14);

        std::cout
            << "Values set successfully!"
            << std::endl;

        std::cout
            << "Division result: "
            << p.divide()
            << std::endl;

        std::cout
            << "Program finished successfully!"
            << std::endl;
    }
    catch (const DivisionByZeroException& exception) {
        std::cout
            << "Division error: "
            << exception.what()
            << std::endl;
    }
    catch (const std::invalid_argument& exception) {
        std::cout
            << "Invalid argument: "
            << exception.what()
            << std::endl;
    }
    catch (const std::exception& exception) {
        std::cout
            << "Unexpected error: "
            << exception.what()
            << std::endl;
    }

    return 0;
}