#pragma once
#include "Territory.h"

class Command
{
	Territory& territory;

public:
	explicit Command(Territory& terr);
	Territory& getTerritory() const;
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual std::string description() const = 0;
	virtual ~Command() = default;
};

