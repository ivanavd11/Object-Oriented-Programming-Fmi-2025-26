#pragma once

#include "AdmissionRequirement.h"
#include "Course.h"

class MinimumCoursesFromCategoryRequirement
    : public AdmissionRequirement {
private:
    CourseCategory category;
    int minimumCount;

public:
    MinimumCoursesFromCategoryRequirement(
        CourseCategory category,
        int minimumCount
    );

    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};