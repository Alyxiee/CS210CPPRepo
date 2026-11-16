#pragma once
#include "Animal.h"

// TODO: same fix as Swimmer.h -- add the same keyword here, between
// "public" and "Animal", for the same reason.
class Runner : public Animal {
public:
    explicit Runner(std::string name);
    void run() const;
};
