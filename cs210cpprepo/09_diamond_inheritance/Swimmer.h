#pragma once
#include "Animal.h"

// TODO: this line currently inherits Animal the plain way. Once we
// build Duck (which inherits both Swimmer and Runner), that gives every
// Duck TWO separate Animal subobjects -- the diamond problem. Add ONE
// keyword between "public" and "Animal" below to make Swimmer and
// Runner share a single Animal subobject instead.
class Swimmer : public Animal {
public:
    explicit Swimmer(std::string name);
    void swim() const;
};
