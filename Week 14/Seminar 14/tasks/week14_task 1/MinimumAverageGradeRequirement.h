#pragma once

#include "AdmissionRequirement.h"

class MinimumAverageGradeRequirement
    : public AdmissionRequirement {
private:
    double minimumGrade;

public:
    explicit MinimumAverageGradeRequirement(
        double minimumGrade
    );

    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};