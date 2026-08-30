#include "MinimumAverageGradeRequirement.h"

#include "Exceptions.h"

#include <iomanip>
#include <memory>
#include <sstream>

MinimumAverageGradeRequirement::
MinimumAverageGradeRequirement(
    double minimumGrade
)
    : minimumGrade(minimumGrade) {
    if (minimumGrade < 2.0 ||
        minimumGrade > 6.0) {
        throw InvalidRequirementConfigurationException(
            "minimum average grade must be "
            "between 2.00 and 6.00."
        );
    }
}

RequirementCheckResult
MinimumAverageGradeRequirement::check(
    const Student& student
) const {
    double studentGrade =
        student.getAverageGrade();

    if (studentGrade >= minimumGrade) {
        return RequirementCheckResult::success();
    }

    std::ostringstream message;

    message << std::fixed
        << std::setprecision(2)
        << "Student average grade is "
        << studentGrade
        << ", but at least "
        << minimumGrade
        << " is required.";

    return RequirementCheckResult::failure(
        message.str()
    );
}

std::unique_ptr<AdmissionRequirement>
MinimumAverageGradeRequirement::clone() const {
    return std::make_unique<
        MinimumAverageGradeRequirement
    >(*this);
}