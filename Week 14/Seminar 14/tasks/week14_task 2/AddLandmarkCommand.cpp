#include "AddLandmarkCommand.h"
#include <stdexcept>

AddLandmarkCommand::AddLandmarkCommand(Territory& target, std::unique_ptr<Landmark> landmark)
	:Command(target), landmark(std::move(landmark)), executed(false)
{
	if (!landmark)
	{
        throw std::invalid_argument("Add command cannot contain an empty landmark.");
    }

    landmarkName = this->landmark->getName();
}

void AddLandmarkCommand::execute()
{
    if (executed) {
        throw std::logic_error("Add command has already been executed." );
    }

    if (!landmark) {
        throw std::logic_error("Add command does not own a landmark.");
    }

    if (this->getTerritory().hasLandmark(landmarkName)) {
        throw std::invalid_argument("Landmark with name "+ landmarkName+ " already exists.");
    }

    this->getTerritory().addLandmark(std::move(landmark));

    executed = true;
}
void AddLandmarkCommand::undo()
{
    if (!executed) {
        throw std::logic_error("Cannot undo an add command that has not been executed.");
    }

    this->getTerritory().removeLandmark(landmarkName);
    executed = false;
}

std::string AddLandmarkCommand::description() const
{
    return "Add landmark: " + landmarkName;
}