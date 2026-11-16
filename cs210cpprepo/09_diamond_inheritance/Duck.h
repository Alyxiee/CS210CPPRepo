#pragma once
#include "Swimmer.h"
#include "Runner.h"

class Duck : public Swimmer, public Runner {
public:
    explicit Duck(std::string name);
};
