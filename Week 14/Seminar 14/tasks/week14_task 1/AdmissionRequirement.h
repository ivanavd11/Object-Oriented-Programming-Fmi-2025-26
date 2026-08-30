#pragma once

#include "RequirementCheckResult.h"
#include "Student.h"

#include <memory>

class AdmissionRequirement {
public:
    virtual RequirementCheckResult check(const Student& student) const = 0;

    virtual std::unique_ptr<AdmissionRequirement> clone() const = 0;

    virtual ~AdmissionRequirement() = default;
};
