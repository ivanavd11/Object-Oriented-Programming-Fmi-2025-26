#include "SetDangerLevelCommand.h"
#include <stdexcept>

SetDangerLevelCommand::SetDangerLevelCommand(Territory& target, int newLevel)
	:Command(target), newLevel(newLevel), executed(false), previousLevel(0)
{
	if (newLevel < 1 || newLevel>10)
	{
		throw std::invalid_argument("Territory danger level must be between 1 and 10.");
	}
}

void SetDangerLevelCommand::execute()
{
	if (executed)
	{
		throw std::logic_error("Danget level command has already been executed.");
	}

	previousLevel = this->getTerritory().getDangerLevel();
	this->getTerritory().setDangerLevel(newLevel);

	executed = true;
}
void SetDangerLevelCommand::undo()
{
	if (!executed) {
		throw std::logic_error("Cannot undo a danget level command that has not been executed.");
	}

	this->getTerritory().setDangerLevel(previousLevel);

	executed = false;
}
std::string SetDangerLevelCommand::description() const
{
	return "Set danger level to " + std::to_string(newLevel);
}