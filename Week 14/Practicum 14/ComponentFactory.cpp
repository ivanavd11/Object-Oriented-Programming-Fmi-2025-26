#include "ComponentFactory.h"

#include "CPU.h"
#include "Memory.h"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

std::optional<std::unique_ptr<Component>>
createComponent() {
    try {
        int componentType;

        std::cout << "Choose component type:\n";
        std::cout << "1. CPU\n";
        std::cout << "2. Memory\n";
        std::cout << "Choice: ";

        if (!(std::cin >> componentType)) {
            return std::nullopt;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        std::string label;

        std::cout << "Enter component label: ";
        std::getline(std::cin, label);

        if (componentType == 1) {
            unsigned int cores;
            unsigned int clockSpeed;

            std::cout << "Enter number of cores: ";

            if (!(std::cin >> cores)) {
                return std::nullopt;
            }

            std::cout << "Enter clock speed in MHz: ";

            if (!(std::cin >> clockSpeed)) {
                return std::nullopt;
            }

            // Проверката е преди преобразуването
            // към unsigned short.
            if (cores >
                std::numeric_limits<unsigned short>::max() ||
                clockSpeed >
                std::numeric_limits<unsigned short>::max()) {
                return std::nullopt;
            }

            std::unique_ptr<Component> component =
                std::make_unique<CPU>(
                    label,
                    static_cast<unsigned short>(cores),
                    static_cast<unsigned short>(clockSpeed)
                );

            return std::optional<std::unique_ptr<Component>>(
                std::move(component)
            );
        }

        if (componentType == 2) {
            unsigned int capacity;

            std::cout << "Enter memory capacity in GB: ";

            if (!(std::cin >> capacity)) {
                return std::nullopt;
            }

            if (capacity >
                std::numeric_limits<unsigned short>::max()) {
                return std::nullopt;
            }

            std::unique_ptr<Component> component =
                std::make_unique<Memory>(
                    label,
                    static_cast<unsigned short>(capacity)
                );

            return std::optional<std::unique_ptr<Component>>(
                std::move(component)
            );
        }

        // Невалиден тип компонент.
        return std::nullopt;
    }
    catch (const std::exception&) {
        // Конструкторът е хвърлил изключение
        // заради невалидни характеристики.
        return std::nullopt;
    }
}
