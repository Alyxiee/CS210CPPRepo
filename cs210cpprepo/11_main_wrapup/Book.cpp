#include "Book.h"
#include <utility>

namespace cs210::library {

    Book::Book(std::string title, std::string author) {
        // TODO: initialize title_ and author_ from the parameters using
        // a member initializer list instead of this body. Rewrite the
        // line above to read:
        //   Book::Book(std::string title, std::string author)
        //       : title_(std::move(title)), author_(std::move(author)) {
    }

}
