#include "ShapesCollection.h"

#include <iostream>
#include <stdexcept>
#include <utility>

ShapesCollection::ShapesCollection()
    : shapes(nullptr), shapesCount(0) {
}

ShapesCollection::ShapesCollection(
    const ShapesCollection& other
)
    : shapes(nullptr), shapesCount(0) {

    copyFrom(other);
}

ShapesCollection& ShapesCollection::operator=(
    const ShapesCollection& other
    ) {
    if (this != &other) {
        ShapesCollection copy(other);

        std::swap(shapes, copy.shapes);
        std::swap(shapesCount, copy.shapesCount);
    }

    return *this;
}

ShapesCollection::ShapesCollection(
    ShapesCollection&& other
) noexcept
    : shapes(nullptr), shapesCount(0) {

    moveFrom(std::move(other));
}

ShapesCollection& ShapesCollection::operator=(
    ShapesCollection&& other
    ) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

ShapesCollection::~ShapesCollection() {
    free();
}

void ShapesCollection::free() {
    for (std::size_t i = 0; i < shapesCount; ++i) {
        delete shapes[i];
    }

    delete[] shapes;

    shapes = nullptr;
    shapesCount = 0;
}

void ShapesCollection::copyFrom(
    const ShapesCollection& other
) {
    if (other.shapesCount == 0) {
        return;
    }

    shapes = new Shape * [other.shapesCount] {};

    try {
        for (std::size_t i = 0;
            i < other.shapesCount;
            ++i) {
            shapes[i] = other.shapes[i]->clone();
        }

        shapesCount = other.shapesCount;
    }
    catch (...) {
        for (std::size_t i = 0;
            i < other.shapesCount;
            ++i) {
            delete shapes[i];
        }

        delete[] shapes;
        shapes = nullptr;
        shapesCount = 0;

        throw;
    }
}

void ShapesCollection::moveFrom(
    ShapesCollection&& other
) noexcept {
    shapes = other.shapes;
    shapesCount = other.shapesCount;

    other.shapes = nullptr;
    other.shapesCount = 0;
}

void ShapesCollection::addShape(Shape* shape) {
    if (shape == nullptr) {
        throw std::invalid_argument(
            "Shape cannot be nullptr."
        );
    }

    Shape** newShapes =
        new Shape * [shapesCount + 1];

    for (std::size_t i = 0; i < shapesCount; ++i) {
        newShapes[i] = shapes[i];
    }

    newShapes[shapesCount] = shape;

    delete[] shapes;

    shapes = newShapes;
    ++shapesCount;
}

void ShapesCollection::printShapes() const 
{
    if (shapesCount == 0) {
        std::cout << "The collection is empty.\n";
        return;
    }

    for (std::size_t i = 0; i < shapesCount; ++i) 
    {
        std::cout << "Shape " << i + 1 << ":\n";
        std::cout << "  Perimeter: "
            << shapes[i]->getPerimeter()
            << '\n';
        std::cout << "  Area: "
            << shapes[i]->getArea()
            << '\n';
    }
}

std::size_t ShapesCollection::getShapesCount() const {
    return shapesCount;
}