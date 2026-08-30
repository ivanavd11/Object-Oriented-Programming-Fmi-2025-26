#ifndef PREMIUM_PLAYER_H
#define PREMIUM_PLAYER_H

#include <string>

#include "LoggedPlayer.h"

class PremiumPlayer : public LoggedPlayer {
private:
    std::string name;

public:
    PremiumPlayer(
        int id,
        const std::string& password,
        const std::string& name
    );

    void setName(const std::string& newName);
    const std::string& getName() const;

    bool levelUp() override;

    void sendMessage(
        const std::string& message
    ) const;

    void printInfo() const override;
};

#endif
