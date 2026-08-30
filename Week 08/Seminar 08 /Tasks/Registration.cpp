#include "Registration.h"

#include <cstring>
#include <stdexcept>
#include <cctype>

using namespace std;

bool Registration::isValid(const char* registration) const
{
    if (registration == nullptr)
    {
        return false;
    }

    size_t len = strlen(registration);

    if (len != 7 && len != 8)
    {
        return false;
    }

    int cityLetters;

    if (len == 7)
    {
        cityLetters = 1;
    }
    else
    {
        cityLetters = 2;
    }

    for (int i = 0; i < cityLetters; i++)
    {
        if (!isalpha(static_cast<unsigned char>(registration[i])))
        {
            return false;
        }
    }

    for (int i = cityLetters;i < cityLetters + 4;i++)
    {
        if (!isdigit(static_cast<unsigned char>(registration[i])))
        {
            return false;
        }
    }

    for (int i = cityLetters + 4; i < cityLetters + 6; i++)
    {
        if (!isalpha(static_cast<unsigned char>(registration[i])))
        {
            return false;
        }
    }
    return true;
}

Registration::Registration(const char* registration)
{
    if (!isValid(registration))
    {
        throw invalid_argument("Invalid registration number!");
    }

    size_t len = strlen(registration);

    for (size_t i = 0; i < len; i++)
    {
        code[i] = toupper(static_cast<unsigned char>(registration[i]));
    }

    code[len] = '\0';
}

const char* Registration::getCode() const
{
    return code;
}

bool Registration::operator==(const Registration& other) const
{
    return strcmp(code, other.code) == 0;
}

bool Registration::operator!=(const Registration& other) const
{
    return !(*this == other);
}

bool Registration::operator<(const Registration& other) const
{
    return strcmp(code, other.code) < 0;
}

bool Registration::operator>(const Registration& other) const
{
    return other < *this;
}

bool Registration::operator<=(const Registration& other) const
{
    return !(*this > other);
}

bool Registration::operator>=(const Registration& other) const
{
    return !(*this < other);
}

ostream& operator<<(ostream& out,const Registration& registration)
{
    out << registration.code;

    return out;
}