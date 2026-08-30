#ifndef GUEST_H
#define GUEST_H

#include "Player.h"

class Guest : public Player {
private:
    unsigned int remainingPlayTime;

public:
    Guest(int id, unsigned int remainingPlayTime);

    void setRemainingPlayTime(unsigned int newTime);
    unsigned int getRemainingPlayTime() const;

    bool levelUp() override;

    void printInfo() const override;
};

#endif
