#include "Swimmer.h"
#include <iostream>

Swimmer::Swimmer(std::string name) : Animal(std::move(name)) {}

void Swimmer::swim() const {
    std::cout << name() << " is swimming." << std::endl;
}
