#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse ==" << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::unique_ptr<List<Player>> tableOne = makeList<Player>();

    tableOne->addFront(new Player(1,"McGEE"));
    tableOne->addFront(new Player(2,"Leon"));
    tableOne->addFront(new Player(3,"Kennedy"));
    tableOne->addFront(new Player(4,"Claire"));

    std::cout << std::endl << "Oh-ho! A new player wants to join! Oh.. it's Bryan..." << std::endl;
    tableOne->addAnywhere(1, new Player(5,"Bryan"));

    std::cout << std::endl << "List Table One" << std::endl;
    tableOne->print();
    std::cout << std::endl << "Bryan joined mid-game and played a reverse!" << std::endl;
    tableOne->reverse();
    std::cout << std::endl << "List Table One Reversed" << std::endl;
    tableOne->print();

    std::cout << std::endl << "Leon won, but Bryan wanted to keep playing. Leon leaves." << std::endl;
    tableOne->deleteAnywhere(1);

    std::unique_ptr<List<Player>> tableTwo = makeList<Player>();

    tableTwo->addFront(new Player(1,"Jacob"));
    tableTwo->addFront(new Player(2,"Edward"));
    tableTwo->addFront(new Player(3,"Charlie"));
    tableTwo->addFront(new Player(4,"Bella"));

    std::cout << std::endl << "Oh hey! Another table wants to join. Also in the middle of the game. Great." << std::endl;
    tableTwo->print();

    std::cout << std::endl << "Merged the tables" << std::endl;
    tableOne->concat(tableTwo.get());

    tableTwo->print();
    tableOne->print();

    int temp = tableOne->getSize();
    for (int i = 0; i < temp; i++) {
        tableOne->deleteAnywhere(i);
    }

    std::cout << std::endl << "Wait.. Where'd everyone go..? It's so lonely here... BINGO" << std::endl;


    tableOne->print();


    return 0;
}
