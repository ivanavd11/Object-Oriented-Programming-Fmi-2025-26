#include "HexColourCode.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void HexColourCode::free()
{
	delete[] code;
	code = nullptr;
}
void HexColourCode::copyFrom(const HexColourCode& other)
{
	code = new char[strlen(other.code) + 1];
	strcpy(code, other.code);
}

bool HexColourCode::isValid(const char* code) const
{
    if (code == nullptr)
    {
        return false;
    }

    if (strlen(code) != 7)
    {
        return false;
    }

    if (code[0] != '#')
    {
        return false;
    }

    for (int i = 1; i < 7; i++)
    {
        if (!(code[i]>='0' && code[i]<='9'))
        {
            return false;
        }
    }

    return true;
}
unsigned int HexColourCode::toNumber() const
{
    unsigned int result = 0;

    for (int i = 1; i < 7; i++)
    {
        result *= 16;

        if (code[i] >= '0' && code[i] <= '9')
        {
            result += code[i] - '0';
        }
        else if (code[i] >= 'A' && code[i] <= 'F')
        {
            result += code[i] - 'A' + 10;
        }
        else
        {
            result += code[i] - 'a' + 10;
        }
    }

    return result;
}

HexColourCode::HexColourCode()
{
    this->code = new char[8];
    strcpy(this->code, "#000000");
}

HexColourCode::HexColourCode(const char* code)
{
    this->code = nullptr;

    if (!isValid(code))
    {
        this->code = new char[8];
        strcpy(this->code, "#000000");

        return;
    }

    this->code = new char[strlen(code) + 1];
    strcpy(this->code, code);
}

HexColourCode::HexColourCode(
    const HexColourCode& other)
{
    copyFrom(other);
}

HexColourCode& HexColourCode::operator=(
    const HexColourCode& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

HexColourCode::~HexColourCode()
{
    free();
}

void HexColourCode::setCode(const char* newCode)
{
    if (!isValid(newCode))
    {
        cout << "Invalid hex code!" << endl;
        return;
    }

    char* newData =
        new char[strlen(newCode) + 1];

    strcpy(newData, newCode);

    delete[] code;

    code = newData;
}

strong_ordering HexColourCode::operator<=>(
    const HexColourCode& other) const
{
    unsigned int first = toNumber();
    unsigned int second = other.toNumber();

    if (first < second)
    {
        return strong_ordering::less;
    }

    if (first > second)
    {
        return strong_ordering::greater;
    }

    return strong_ordering::equal;
}

bool HexColourCode::operator==(
    const HexColourCode& other) const
{
    return toNumber() == other.toNumber();
}

ostream& operator<<(
    ostream& out,
    const HexColourCode& color)
{
    out << color.code;

    return out;
}

