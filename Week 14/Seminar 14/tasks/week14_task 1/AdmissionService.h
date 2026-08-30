#pragma once

#include "AdmissionReport.h"
#include "AdmissionRequirement.h"

#include <cstddef>
#include <memory>
#include <vector>

class AdmissionService {
private:
    std::vector<
        std::unique_ptr<AdmissionRequirement>
    > requirements;

    void copyFrom(
        const AdmissionService& other
    );

public:
    AdmissionService() = default;

    AdmissionService(
        const AdmissionService& other
    );

    AdmissionService& operator=(
        const AdmissionService& other
        );

    AdmissionService(
        AdmissionService&& other
    ) noexcept = default;

    AdmissionService& operator=(
        AdmissionService&& other
        ) noexcept = default;

    ~AdmissionService() = default;

    void addRequirement(
        std::unique_ptr<AdmissionRequirement>
        requirement
    );

    void addRequirement(
        const AdmissionRequirement& requirement
    );

    std::size_t requirementsCount() const;

    AdmissionReport checkAdmission(
        const Student& student
    ) const;
};