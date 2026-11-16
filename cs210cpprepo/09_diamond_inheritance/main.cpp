// TASK 09 -- Proving there's only one Animal inside a Duck

#include <iostream>
#include "Duck.h"

int main() {
    Duck donald("Donald");

    donald.swim();
    donald.run();

    // This line is only legal because of "virtual" in Swimmer.h and
    // Runner.h. It upcasts a Duck to a plain Animal reference. Without
    // virtual inheritance, the compiler would have to ask "which
    // Animal, the one through Swimmer or the one through Runner?" and
    // refuse to guess, giving an "ambiguous conversion" error.
    Animal& asAnimal = donald;
    std::cout << "Name via base Animal reference: " << asAnimal.name()
              << std::endl;

    return 0;
}

// BEFORE YOU FILL IN THE TODOs: build this target as-is first. You
// should get an "ambiguous conversion from Duck to Animal" error (or
// "ambiguous base class" on Duck.cpp's Animal(name) init line). Read
// that error together -- it IS the diamond problem, made visible on
// screen instead of staying a diagram on the board. THEN go add the
// missing keyword in Swimmer.h and Runner.h and rebuild again.
