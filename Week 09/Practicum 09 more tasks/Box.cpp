#include <print>
#include <memory>

constexpr double DEFAULT_WEIGHT = 0;

class Box {
    double weight;

public:
    Box(double _weight = DEFAULT_WEIGHT) : weight(_weight) {}

    void setWeight(double _weight) {
        if (_weight < 0)
            return;

        weight = _weight;
    }

    double getWeight() const {
        return weight;
    }
};

int main() {
    std::unique_ptr<Box> simpleBox = std::make_unique<Box>(0);
    simpleBox->setWeight(3.14);
    println("{}", simpleBox->getWeight());
}