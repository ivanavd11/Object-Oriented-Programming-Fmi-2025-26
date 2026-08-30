#include "RemoveLandmarkCommand.h"
#include <stdexcept>

RemoveLandmarkCommand::RemoveLandmarkCommand(Territory& target, const std::string& landmarkName)
	:Command(target), landmarkName(landmarkName), executed(false)
{
	if (landmarkName.empty())
	{
		throw std::invalid_argument("Landmark name cannot be empty.");
	}
}

void RemoveLandmarkCommand::execute()
{
	if (executed)
	{
		throw std::logic_error("Remove command has already been executed.");
	}

	removedLandmark =this->getTerritory().removeLandmark(landmarkName);

	executed = true;
}
void RemoveLandmarkCommand::undo()
{
	if (!executed) {
		throw std::logic_error("Cannot undo a remove command that has not been executed.");
	}

	if (!removedLandmark) {
		throw std::logic_error("Remove command does not own the removed landmark.");
	}

	if (this->getTerritory().hasLandmark(landmarkName))
	{
		throw std::logic_error("Cannot restore landmark because another landmark with the same name already exists.");
	}

	this->getTerritory().addLandmark(std::move(removedLandmark));

	executed = false;
}
std::string RemoveLandmarkCommand::description() const
{
	return "Remove landmark: "+ landmarkName;
}