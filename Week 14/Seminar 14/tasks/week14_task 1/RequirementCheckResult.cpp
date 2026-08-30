#include "RequirementCheckResult.h"

RequirementCheckResult::RequirementCheckResult(
    bool satisfied,
    const std::string& message
)
    : satisfied(satisfied),
    message(message) {
}

bool RequirementCheckResult::isSatisfied() const {
    return satisfied;
}

const std::string&
RequirementCheckResult::getMessage() const {
    return message;
}

RequirementCheckResult
RequirementCheckResult::success() {
    return RequirementCheckResult(true);
}

RequirementCheckResult
RequirementCheckResult::failure(
    const std::string& message
) {
    return RequirementCheckResult(false, message);
}