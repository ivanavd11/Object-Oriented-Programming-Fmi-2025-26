#include "Course.h"
#include <stdexcept>

Course::Course(const std::string& name, int credits, CourseCategory category, bool mandatory, bool passed)
	:name(name), credits(credits), category(category), mandatory(mandatory), passed(passed)
{
	if (name.empty())
	{
		throw std::invalid_argument("Name must be not empty");
	}
	if (credits <= 0)
	{
		throw std::invalid_argument("Credits must be positiv");
	}
	
}

const std::string& Course::getName() const
{
	return name;
}
int Course::getCredits() const
{
	return credits;
}
CourseCategory Course::getCategory() const
{
	return category;
}

bool Course::isMandatory() const
{
	return mandatory;
}
bool Course::isPassed() const
{
	return passed;
}

const char* categoryToString(CourseCategory category) {
	switch (category) {
	case CourseCategory::Programming:
		return "Programming";

	case CourseCategory::Mathematics:
		return "Mathematics";

	case CourseCategory::AppliedMathematics:
		return "Applied Mathematics";

	case CourseCategory::Other:
		return "Other";
	}

	return "Unknown";
}