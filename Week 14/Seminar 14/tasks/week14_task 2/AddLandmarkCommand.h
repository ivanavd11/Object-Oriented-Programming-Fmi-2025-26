#pragma once
#include "Command.h"
class AddLandmarkCommand : public Command
{
private:
	std::unique_ptr<Landmark> landmark;
	std::string landmarkName;
	bool executed;
public:
	AddLandmarkCommand(Territory& target,std::unique_ptr<Landmark> landmark);

	void execute() override;
	void undo() override;
	std::string description() const override;
};

