#pragma once

#include <string>

class RequirementCheckResult {
private:
    bool satisfied;
    std::string message;

public:
    RequirementCheckResult(
        bool satisfied,
        const std::string& message = ""
    );

    bool isSatisfied() const;
    const std::string& getMessage() const;

    static RequirementCheckResult success();

    static RequirementCheckResult failure(
        const std::string& message
    );
};

