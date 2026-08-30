#include "MinimumElectiveCreditsRequirement.h"

#include "Exceptions.h"

#include <memory>
#include <string>

MinimumElectiveCreditsRequirement::
MinimumElectiveCreditsRequirement(
    int minimumCredits
)
    : minimumCredits(minimumCredits) {
    if (minimumCredits < 0) {
        throw InvalidRequirementConfigurationException(
            "minimum elective credits cannot be negative."
        );
    }
}

RequirementCheckResult
MinimumElectiveCreditsRequirement::check(
    const Student& student
) const {
    int actualCredits =
        student.getPassedElectiveCredits();

    if (actualCredits >= minimumCredits) {
        return RequirementCheckResult::success();
    }

    std::string message =
        "Student has "
        + std::to_string(actualCredits)
        + " elective credits, but at least "
        + std::to_string(minimumCredits)
        + " are required.";

    return RequirementCheckResult::failure(message);
}

std::unique_ptr<AdmissionRequirement>
MinimumElectiveCreditsRequirement::clone() const {
    return std::make_unique<
        MinimumElectiveCreditsRequirement
    >(*this);
}