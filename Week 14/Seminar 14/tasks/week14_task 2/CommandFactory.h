#pragma once
#include <memory>
#include "Command.h"

class CommandFactory
{
public:

    static std::unique_ptr<Command> create(
        const std::string& type, // "add" | "remove" | "danger"
        const std::string& args, // зависи от типа
        Territory& target
    );
};

