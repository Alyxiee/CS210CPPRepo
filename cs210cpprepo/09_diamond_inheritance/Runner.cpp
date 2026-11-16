#include "Runner.h"
#include <iostream>

Runner::Runner(std::string name) : Animal(std::move(name)) {}

void Runner::run() const {
    std::cout << name() << " is running." << std::endl;
}
