#include "MinimumCreditsRequirement.h"

#include "Exceptions.h"

#include <memory>
#include <string>

MinimumCreditsRequirement::MinimumCreditsRequirement(int minimumCredits)
    : minimumCredits(minimumCredits) {
    if (minimumCredits < 0) {
        throw InvalidRequirementConfigurationException("minimum credits cannot be negative.");
    }
}

RequirementCheckResult MinimumCreditsRequirement::check(const Student& student) const {
    int studentCredits =student.getAccumulatedCredits();

    if (studentCredits >= minimumCredits) {
        return RequirementCheckResult::success();
    }

    std::string message =
        "Student has "
        + std::to_string(studentCredits)
        + " credits, but at least "
        + std::to_string(minimumCredits)
        + " are required.";

    return RequirementCheckResult::failure(message);
}

std::unique_ptr<AdmissionRequirement>MinimumCreditsRequirement::clone() const {
    return std::make_unique<MinimumCreditsRequirement>(*this);
}