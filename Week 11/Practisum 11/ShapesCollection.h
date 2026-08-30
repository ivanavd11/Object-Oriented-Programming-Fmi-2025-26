#pragma once
#ifndef SHAPES_COLLECTION_H
#define SHAPES_COLLECTION_H

#include <cstddef>

#include "Shape.h"

class ShapesCollection 
{
private:
    Shape** shapes;
    std::size_t shapesCount;

    void free();
    void copyFrom(const ShapesCollection& other);
    void moveFrom(ShapesCollection&& other) noexcept;

public:
    ShapesCollection();

    ShapesCollection(const ShapesCollection& other);

    ShapesCollection& operator=(const ShapesCollection& other);

    ShapesCollection(ShapesCollection&& other) noexcept;

    ShapesCollection& operator=(ShapesCollection&& other) noexcept;

    ~ShapesCollection();

    void addShape(Shape* shape);

    void printShapes() const;

    std::size_t getShapesCount() const;
};

#endif
