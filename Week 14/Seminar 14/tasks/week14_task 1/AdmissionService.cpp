#include "AdmissionService.h"

#include <stdexcept>
#include <utility>

void AdmissionService::copyFrom(
    const AdmissionService& other
) {
    requirements.reserve(
        other.requirements.size()
    );

    for (const auto& requirement
        : other.requirements) {
        requirements.push_back(
            requirement->clone()
        );
    }
}

AdmissionService::AdmissionService(
    const AdmissionService& other
) {
    copyFrom(other);
}

AdmissionService&
AdmissionService::operator=(
    const AdmissionService& other
    ) {
    if (this != &other) {
        AdmissionService copy(other);

        requirements.swap(
            copy.requirements
        );
    }

    return *this;
}

void AdmissionService::addRequirement(
    std::unique_ptr<AdmissionRequirement>
    requirement
) {
    if (!requirement) {
        throw std::invalid_argument(
            "Cannot add an empty requirement."
        );
    }

    requirements.push_back(
        std::move(requirement)
    );
}

void AdmissionService::addRequirement(
    const AdmissionRequirement& requirement
) {
    requirements.push_back(
        requirement.clone()
    );
}

std::size_t
AdmissionService::requirementsCount() const {
    return requirements.size();
}

AdmissionReport
AdmissionService::checkAdmission(
    const Student& student
) const {
    AdmissionReport report;

    for (const auto& requirement
        : requirements) {
        RequirementCheckResult result =
            requirement->check(student);

        if (!result.isSatisfied()) {
            report.addFailure(
                result.getMessage()
            );
        }
    }

    return report;
}