#include "AllMandatoryCoursesPassedRequirement.h"

#include <memory>
#include <string>

RequirementCheckResult
AllMandatoryCoursesPassedRequirement::check(
    const Student& student
) const {
    std::string failedCourses;

    for (const Course& course
        : student.getCourses()) {
        if (course.isMandatory() &&
            !course.isPassed()) {
            if (!failedCourses.empty()) {
                failedCourses += ", ";
            }

            failedCourses += course.getName();
        }
    }

    if (failedCourses.empty()) {
        return RequirementCheckResult::success();
    }

    return RequirementCheckResult::failure(
        "Mandatory courses not passed: "
        + failedCourses
        + "."
    );
}

std::unique_ptr<AdmissionRequirement>
AllMandatoryCoursesPassedRequirement::
clone() const {
    return std::make_unique<
        AllMandatoryCoursesPassedRequirement
    >(*this);
}