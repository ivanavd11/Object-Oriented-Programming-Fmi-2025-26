#include "AdmissionReport.h"

bool AdmissionReport::isAdmitted() const {
    return failureReasons.empty();
}

const std::vector<std::string>&
AdmissionReport::getFailureReasons() const {
    return failureReasons;
}

void AdmissionReport::addFailure(
    const std::string& reason
) {
    failureReasons.push_back(reason);
}

std::ostream& operator<<(
    std::ostream& os,
    const AdmissionReport& report
    ) {
    if (report.isAdmitted()) {
        os << "Student is admitted "
            "to the final exam.\n";

        return os;
    }

    os << "Student is not admitted "
        "to the final exam:\n";

    for (const std::string& reason
        : report.getFailureReasons()) {
        os << "- " << reason << '\n';
    }

    return os;
}