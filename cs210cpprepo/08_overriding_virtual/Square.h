#pragma once
#include "Shape.h"

class Square : public Shape {
public:
    explicit Square(double side);

    double area() const override;
    std::string name() const override;

private:
    double side_;
};
