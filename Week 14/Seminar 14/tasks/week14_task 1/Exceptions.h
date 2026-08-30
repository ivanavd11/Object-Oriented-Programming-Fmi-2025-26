#pragma once

#include <stdexcept>
#include <string>

class InvalidRequirementConfigurationException: public std::invalid_argument {
public:
    explicit InvalidRequirementConfigurationException(const std::string& message)
        : std::invalid_argument("Invalid requirement configuration: "+ message) 
    {
    }
};

class DuplicateStudentException
    : public std::runtime_error {
public:
    explicit DuplicateStudentException(
        const std::string& facultyNumber
    )
        : std::runtime_error(
            "Student with faculty number "
            + facultyNumber
            + " already exists."
        ) {
    }
};

class StudentNotFoundException
    : public std::runtime_error {
public:
    explicit StudentNotFoundException(
        const std::string& facultyNumber
    )
        : std::runtime_error(
            "Student with faculty number "
            + facultyNumber
            + " was not found."
        ) {
    }
};