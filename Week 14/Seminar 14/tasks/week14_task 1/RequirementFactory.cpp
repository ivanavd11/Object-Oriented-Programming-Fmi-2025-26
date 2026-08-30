#include "RequirementFactory.h"

#include "AllMandatoryCoursesPassedRequirement.h"
#include "Exceptions.h"
#include "MaximumRemainingElectivesRequirement.h"
#include "MinimumAverageGradeRequirement.h"
#include "MinimumCoursesFromCategoryRequirement.h"
#include "MinimumCreditsRequirement.h"
#include "MinimumElectiveCreditsRequirement.h"
#include "RequiredCoursesRequirement.h"

#include <memory>
#include <string>
#include <vector>

std::unique_ptr<AdmissionRequirement>
RequirementFactory::createMinimumCredits(
    int credits
) {
    if (credits < 0) {
        throw InvalidRequirementConfigurationException(
            "minimum credits cannot be negative."
        );
    }

    return std::make_unique<
        MinimumCreditsRequirement
    >(credits);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::createRequiredCourses(
    const std::vector<std::string>& courseNames
) {
    if (courseNames.empty()) {
        throw InvalidRequirementConfigurationException(
            "required course list cannot be empty."
        );
    }

    for (const std::string& courseName
        : courseNames) {
        if (courseName.empty()) {
            throw InvalidRequirementConfigurationException(
                "required course name cannot be empty."
            );
        }
    }

    return std::make_unique<
        RequiredCoursesRequirement
    >(courseNames);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::
createMinimumCoursesFromCategory(
    CourseCategory category,
    int count
) {
    if (count < 0) {
        throw InvalidRequirementConfigurationException(
            "minimum course count cannot be negative."
        );
    }

    return std::make_unique<
        MinimumCoursesFromCategoryRequirement
    >(category, count);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::createMinimumElectiveCredits(
    int credits
) {
    if (credits < 0) {
        throw InvalidRequirementConfigurationException(
            "minimum elective credits "
            "cannot be negative."
        );
    }

    return std::make_unique<
        MinimumElectiveCreditsRequirement
    >(credits);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::
createMaximumRemainingElectives(
    int maximumCount
) {
    if (maximumCount < 0) {
        throw InvalidRequirementConfigurationException(
            "maximum remaining electives "
            "cannot be negative."
        );
    }

    return std::make_unique<
        MaximumRemainingElectivesRequirement
    >(maximumCount);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::createMinimumAverageGrade(
    double grade
) {
    if (grade < 2.0 || grade > 6.0) {
        throw InvalidRequirementConfigurationException(
            "minimum average grade must be "
            "between 2.00 and 6.00."
        );
    }

    return std::make_unique<
        MinimumAverageGradeRequirement
    >(grade);
}

std::unique_ptr<AdmissionRequirement>
RequirementFactory::
createAllMandatoryCoursesPassed() {
    return std::make_unique<
        AllMandatoryCoursesPassedRequirement
    >();
}