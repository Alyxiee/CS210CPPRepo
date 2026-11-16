// TASK 09 -- The diamond problem
//
// The shape we're building:
//
//              Animal
//             /      \
//         Swimmer    Runner
//             \      /
//              Duck
//
// A Duck is-a Swimmer AND is-a Runner, and both of those are-an Animal.
// The question this task answers: how many Animal "parts" does a
// single Duck object actually contain? Without help, the honest
// answer is TWO, and that's a problem.

#pragma once
#include <string>

class Animal {
public:
    explicit Animal(std::string name);
    virtual ~Animal() = default;

    std::string name() const;

protected:
    std::string name_;
};
