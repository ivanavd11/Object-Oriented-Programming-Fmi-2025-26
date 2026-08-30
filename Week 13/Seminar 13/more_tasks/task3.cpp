#include <iostream>
#include <string>

class Reward {
private:
    unsigned int pointsCost;

protected:
    explicit Reward(unsigned int pointsCost)
        : pointsCost(pointsCost) {}

public:
    unsigned int getPointsCost() const {
        return pointsCost;
    }

    virtual void visualize() const = 0;

    virtual ~Reward() = default;
};

class Penguin : public Reward {
public:
    Penguin() : Reward(50) {}

    void visualize() const override {
        std::cout << "Penguin - 50 points\n";
    }
};

class Pacman : public Reward {
public:
    Pacman() : Reward(150) {}

    void visualize() const override {
        std::cout << "Pacman - 150 points\n";
    }
};

class ComputerBoy : public Reward {
public:
    ComputerBoy() : Reward(500) {}

    void visualize() const override {
        std::cout << "ComputerBoy - 500 points\n";
    }
};

class Squidward : public Reward {
public:
    Squidward() : Reward(1000) {}

    void visualize() const override {
        std::cout << "Squidward - 1000 points\n";
    }
};

class Sylvester : public Reward {
public:
    Sylvester() : Reward(1500) {}

    void visualize() const override {
        std::cout << "Sylvester - 1500 points\n";
    }
};

int main() {
    Penguin penguin;
    Pacman pacman;
    ComputerBoy computerBoy;
    Squidward squidward;
    Sylvester sylvester;

    penguin.visualize();
    pacman.visualize();
    computerBoy.visualize();
    squidward.visualize();
    sylvester.visualize();

    std::cout << "\nPacman costs "
        << pacman.getPointsCost()
        << " points.\n";

    return 0;
}