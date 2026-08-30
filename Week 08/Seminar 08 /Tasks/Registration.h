#pragma once
#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

class Registration
{
private:
    char code[9];

    bool isValid(const char* registration) const;

public:
    Registration(const char* registration);

    const char* getCode() const;

    bool operator==(const Registration& other) const;
    bool operator!=(const Registration& other) const;

    bool operator<(const Registration& other) const;
    bool operator<=(const Registration& other) const;

    bool operator>(const Registration& other) const;
    bool operator>=(const Registration& other) const;

    friend std::ostream& operator<<(std::ostream& out,const Registration& registration);
};

#endif