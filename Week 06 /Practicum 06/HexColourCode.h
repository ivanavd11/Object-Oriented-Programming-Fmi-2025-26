#pragma once

class HexColourCode {
private:
	char* code;

	void free();
	void copyFrom(const HexColourCode& other);

	bool isValid(const char* code) const;
	unsigned int toNumber() const;
public:
	HexColourCode();
	HexColourCode(const char* newCode);
	HexColourCode(const HexColourCode& other);
	HexColourCode& operator=(const HexColourCode& other);
	~HexColourCode();

	void setCode(const char* code);

	friend std::ostream& operator<<(std::ostream& os, const HexColourCode& other);

	std::strong_ordering operator<=>(const HexColourCode&& other) const;

	bool operator==(const HexColourCode& other) const;
	
	HexColourCode operator+(const HexColourCode& other) = delete;
	HexColourCode operator-(const HexColourCode& other) = delete;
	HexColourCode operator*(const HexColourCode& other) = delete;
	HexColourCode  operator/(const HexColourCode& other) = delete;
	HexColourCode operator%(const HexColourCode& other) = delete;

};
