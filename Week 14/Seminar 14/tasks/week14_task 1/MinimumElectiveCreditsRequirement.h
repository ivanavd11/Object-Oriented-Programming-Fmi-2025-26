#pragma once

#include "AdmissionRequirement.h"

class MinimumElectiveCreditsRequirement
    : public AdmissionRequirement {
private:
    int minimumCredits;

public:
    explicit MinimumElectiveCreditsRequirement(
        int minimumCredits
    );

    RequirementCheckResult check(
        const Student& student
    ) const override;

    std::unique_ptr<AdmissionRequirement>
        clone() const override;
};