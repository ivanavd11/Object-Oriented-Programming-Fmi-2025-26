#include "RequiredCoursesRequirement.h"

#include "Exceptions.h"

#include <memory>
#include <string>

RequiredCoursesRequirement::
RequiredCoursesRequirement(
    const std::vector<std::string>&
    requiredCourseNames
)
    : requiredCourseNames(requiredCourseNames) {
    if (requiredCourseNames.empty()) {
        throw InvalidRequirementConfigurationException(
            "required course list cannot be empty."
        );
    }

    for (const std::string& courseName
        : requiredCourseNames) {
        if (courseName.empty()) {
            throw InvalidRequirementConfigurationException(
                "required course name cannot be empty."
            );
        }
    }
}

RequirementCheckResult
RequiredCoursesRequirement::check(
    const Student& student
) const {
    std::string missingCourses;

    for (const std::string& courseName
        : requiredCourseNames) {
        if (!student.hasPassedCourse(courseName)) {
            if (!missingCourses.empty()) {
                missingCourses += ", ";
            }

            missingCourses += courseName;
        }
    }

    if (missingCourses.empty()) {
        return RequirementCheckResult::success();
    }

    return RequirementCheckResult::failure(
        "Required courses not passed: "
        + missingCourses
        + "."
    );
}

std::unique_ptr<AdmissionRequirement>
RequiredCoursesRequirement::clone() const {
    return std::make_unique<
        RequiredCoursesRequirement
    >(*this);
}