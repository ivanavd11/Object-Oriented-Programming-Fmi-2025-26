#pragma once

#include "AdmissionRequirement.h"

class MaximumRemainingElectivesRequirement
    : public AdmissionRequirement {
private:
    int maximumCount;

public:
    explicit MaximumRemainingElectivesRequirement(
        int maximumCount
    );

    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};
