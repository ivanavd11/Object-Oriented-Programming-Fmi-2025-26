#pragma once

#include "AdmissionRequirement.h"

#include <string>
#include <vector>

class RequiredCoursesRequirement
    : public AdmissionRequirement {
private:
    std::vector<std::string> requiredCourseNames;

public:
    explicit RequiredCoursesRequirement(
        const std::vector<std::string>&
        requiredCourseNames
    );

    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};

