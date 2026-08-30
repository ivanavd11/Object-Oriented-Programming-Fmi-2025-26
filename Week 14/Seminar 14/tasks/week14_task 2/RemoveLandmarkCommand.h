#pragma once
#include "Command.h"

class RemoveLandmarkCommand : public Command
{
	std::string landmarkName;
	std::unique_ptr<Landmark> removedLandmark;
	bool executed;

public:
	RemoveLandmarkCommand(Territory& target, const std::string& landmarkName);

	void execute() override;
	void undo() override;
	std::string description() const override;
};

