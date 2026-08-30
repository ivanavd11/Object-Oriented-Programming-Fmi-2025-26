#pragma once

#include <ostream>
#include <string>
#include <vector>

class AdmissionReport {
private:
    std::vector<std::string> failureReasons;

public:
    bool isAdmitted() const;

    const std::vector<std::string>&
        getFailureReasons() const;

    void addFailure(
        const std::string& reason
    );
};

std::ostream& operator<<(
    std::ostream& os,
    const AdmissionReport& report
    );