#include "Duck.h"
#include <utility>

// Because Animal is a VIRTUAL base of both Swimmer and Runner, the
// language rule is: the MOST DERIVED class (here, Duck) is responsible
// for constructing the shared Animal subobject directly, no matter how
// many levels of inheritance sit in between. So Duck's initializer
// list names Animal explicitly, even though Duck doesn't inherit from
// Animal directly on paper.
//
// Swimmer(name) and Runner(name) are still listed below because Duck
// needs to construct its Swimmer part and Runner part too. Their own
// "Animal(name)" initializers (inside Swimmer.cpp and Runner.cpp) are
// simply ignored for this object, since Animal was already built by
// Duck's own initializer list entry.
Duck::Duck(std::string name)
    : Animal(name), Swimmer(name), Runner(std::move(name)) {}
