#pragma once

#include "AdmissionRequirement.h"

class AllMandatoryCoursesPassedRequirement
    : public AdmissionRequirement {
public:
    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};