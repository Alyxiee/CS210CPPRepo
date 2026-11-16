#include "Animal.h"
#include <utility>

Animal::Animal(std::string name) {
    // TODO: initialize name_ from the parameter using a member
    // initializer list instead of this body. Rewrite the line above to
    // read:
    //   Animal::Animal(std::string name) : name_(std::move(name)) {
}

std::string Animal::name() const {
    return name_;
}
