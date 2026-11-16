#pragma once
#include <vector>
#include "Book.h"

namespace cs210::library {

    class Catalog {
    public:
        void addBook(const Book& book);
        void printAll() const;
        int count() const;

    private:
        std::vector<Book> books_;
    };

}
