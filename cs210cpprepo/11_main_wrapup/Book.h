// TASK 11 -- Capstone: everything from today, in one small program
//
// A namespaced class, built with a modern constructor, used through
// its own object. Nothing new here conceptually, just Tasks 03-06
// working together.

#pragma once
#include <string>

namespace cs210::library {   // C++17 nested namespace shorthand for
                              // "namespace cs210 { namespace library { ... } }"

    class Book {
    public:
        Book(std::string title, std::string author);

        std::string title() const { return title_; }
        std::string author() const { return author_; }

    private:
        std::string title_;
        std::string author_;
    };

}
