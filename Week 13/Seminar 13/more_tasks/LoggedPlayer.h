#ifndef LOGGED_PLAYER_H
#define LOGGED_PLAYER_H

#include <string>

#include "Player.h"

class LoggedPlayer : public Player {
private:
    std::string password;

    static void validatePassword(
        const std::string& password
    );

public:
    LoggedPlayer(
        int id,
        const std::string& password
    );

    void setPassword(const std::string& newPassword);

    bool login(
        int enteredId,
        const std::string& enteredPassword
    ) const;

    bool levelUp() override;

    void printInfo() const override;
};

#endif

