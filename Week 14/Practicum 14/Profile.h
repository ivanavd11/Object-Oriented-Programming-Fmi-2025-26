#pragma once
#include <string>
class Profile
{
private:
	std::string username;
public:
    explicit Profile(const std::string& username)
        : username(username) {}

    const std::string& getUsername() const {
        return username;
    }

    void setUsername(const std::string& newUsername) {
        username = newUsername;
    }

    virtual ~Profile() = default;
};

