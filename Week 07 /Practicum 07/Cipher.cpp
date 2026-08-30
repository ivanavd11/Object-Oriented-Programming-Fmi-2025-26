#include "Cipher.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

Cipher::Cipher(const string& text)
{
    this->text = text;
}

string Cipher::encrypt() const
{
    string result = text;

    size_t i = 0;

    while (i < result.size())
    {
        while (i < result.size() && result[i] == ' ')
        {
            i++;
        }

        size_t start = i;

        while (i < result.size() && result[i] != ' ')
        {
            i++;
        }

        size_t end = i;

        reverse(result.begin() + start,
            result.begin() + end);
    }

    return result;
}

string Cipher::operator[](size_t index) const
{
    size_t currentWord = 0;
    size_t i = 0;

    while (i < text.size())
    {
        while (i < text.size() && text[i] == ' ')
        {
            i++;
        }

        size_t start = i;

        while (i < text.size() && text[i] != ' ')
        {
            i++;
        }

        size_t end = i;

        if (start != end)
        {
            if (currentWord == index)
            {
                return text.substr(start, end - start);
            }

            currentWord++;
        }
    }

    throw out_of_range("Invalid word index!");
}

Cipher Cipher::operator+(const Cipher& other) const
{
    return Cipher(text + other.text);
}

Cipher& Cipher::operator+=(const Cipher& other)
{
    text += other.text;

    return *this;
}