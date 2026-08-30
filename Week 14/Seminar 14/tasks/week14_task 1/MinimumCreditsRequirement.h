#pragma once

#include "AdmissionRequirement.h"

class MinimumCreditsRequirement
    : public AdmissionRequirement {
private:
    int minimumCredits;

public:
    explicit MinimumCreditsRequirement(int minimumCredits);

    RequirementCheckResult check( const Student& student) const override;

    std::unique_ptr<AdmissionRequirement> clone() const override;
};