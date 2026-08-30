#pragma once

#include "AdmissionRequirement.h"
#include "Course.h"

#include <memory>
#include <string>
#include <vector>

class RequirementFactory {
public:
    static std::unique_ptr<AdmissionRequirement>
        createMinimumCredits(int credits);

    static std::unique_ptr<AdmissionRequirement>
        createRequiredCourses(
            const std::vector<std::string>& courseNames
        );

    static std::unique_ptr<AdmissionRequirement>
        createMinimumCoursesFromCategory(
            CourseCategory category,
            int count
        );

    static std::unique_ptr<AdmissionRequirement>
        createMinimumElectiveCredits(int credits);

    static std::unique_ptr<AdmissionRequirement>
        createMaximumRemainingElectives(
            int maximumCount
        );

    static std::unique_ptr<AdmissionRequirement>
        createMinimumAverageGrade(double grade);

    static std::unique_ptr<AdmissionRequirement>
        createAllMandatoryCoursesPassed();
};
