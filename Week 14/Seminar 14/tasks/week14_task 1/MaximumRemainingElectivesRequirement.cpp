#include "MaximumRemainingElectivesRequirement.h"

#include "Exceptions.h"

#include <memory>
#include <string>

MaximumRemainingElectivesRequirement::
MaximumRemainingElectivesRequirement(
    int maximumCount
)
    : maximumCount(maximumCount) {
    if (maximumCount < 0) {
        throw InvalidRequirementConfigurationException(
            "maximum remaining electives "
            "cannot be negative."
        );
    }
}

RequirementCheckResult
MaximumRemainingElectivesRequirement::check(
    const Student& student
) const {
    int remainingElectives =
        student.countRemainingElectives();

    if (remainingElectives <= maximumCount) {
        return RequirementCheckResult::success();
    }

    std::string message =
        "Student has "
        + std::to_string(remainingElectives)
        + " remaining elective courses, but at most "
        + std::to_string(maximumCount)
        + " are allowed.";

    return RequirementCheckResult::failure(message);
}

std::unique_ptr<AdmissionRequirement>
MaximumRemainingElectivesRequirement::
clone() const {
    return std::make_unique<
        MaximumRemainingElectivesRequirement
    >(*this);
}