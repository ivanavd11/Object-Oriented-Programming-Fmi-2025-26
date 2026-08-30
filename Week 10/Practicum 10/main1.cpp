#include <iostream>
#include <memory>

#include "Apartment.h"
#include "Tennant.h"

int main() {
    auto apartment1 = std::make_shared<Apartment>(
        "Sofia, Vitosha 10", 3
    );

    auto apartment2 = std::make_shared<Apartment>(
        "Blagoevgrad, Rila 20", 2
    );

    Tennant person1("Ivan", "Ivanov", apartment1);
    Tennant person2("Maria", "Petrova", apartment1);
    Tennant person3("Georgi", "Georgiev", apartment2);

    person1.printInformation();
    person2.printInformation();
    person3.printInformation();

    std::cout << "\nApartment 1 tenants: "
        << apartment1->getNumberOfTenants()
        << '\n';

    std::cout << "Apartment 2 tenants: "
        << apartment2->getNumberOfTenants()
        << '\n';

    std::cout << "\nMaria changes her residence.\n";

    person2.changeResidence(apartment2);
    person2.printInformation();

    std::cout << "\nApartment 1 tenants: "
        << apartment1->getNumberOfTenants()
        << '\n';

    std::cout << "Apartment 2 tenants: "
        << apartment2->getNumberOfTenants()
        << '\n';

    return 0;
}