#pragma once
#include "Command.h"

class SetDangerLevelCommand : public Command
{
	int previousLevel;
	int newLevel;
	bool executed;
public:
	SetDangerLevelCommand(Territory& target, int newLevel);

	void execute() override;
	void undo() override;
	std::string description() const override;

};

