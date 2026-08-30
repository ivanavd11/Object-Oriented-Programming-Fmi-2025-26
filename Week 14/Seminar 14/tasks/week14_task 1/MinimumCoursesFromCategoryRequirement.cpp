#include "MinimumCoursesFromCategoryRequirement.h"

#include "Exceptions.h"

#include <memory>
#include <string>

MinimumCoursesFromCategoryRequirement::
MinimumCoursesFromCategoryRequirement(
    CourseCategory category,
    int minimumCount
)
    : category(category),
    minimumCount(minimumCount) {
    if (minimumCount < 0) {
        throw InvalidRequirementConfigurationException(
            "minimum course count cannot be negative."
        );
    }
}

RequirementCheckResult
MinimumCoursesFromCategoryRequirement::check(
    const Student& student
) const {
    int actualCount =
        student.countPassedCoursesFromCategory(
            category
        );

    if (actualCount >= minimumCount) {
        return RequirementCheckResult::success();
    }

    std::string message =
        "Student has "
        + std::to_string(actualCount)
        + " passed courses from category "
        + categoryToString(category)
        + ", but at least "
        + std::to_string(minimumCount)
        + " are required.";

    return RequirementCheckResult::failure(message);
}

std::unique_ptr<AdmissionRequirement>
MinimumCoursesFromCategoryRequirement::
clone() const {
    return std::make_unique<
        MinimumCoursesFromCategoryRequirement
    >(*this);
}