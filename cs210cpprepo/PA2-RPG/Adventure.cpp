#include "Adventure.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// ===================== GIVEN HELPERS (do not change) =====================

// Reads the next line that is not blank.
// Spaces at the start of the line are removed.
// Returns false when the file has no more lines.
bool Adventure::nextLine(std::ifstream& in, std::string& line) {
    std::string raw;
    while (std::getline(in, raw)) {
        int start = 0;
        while (start < (int)raw.size() && (raw[start] == ' ' || raw[start] == '\t')) {
            start++;
        }
        line = raw.substr(start);
        // Files saved on Windows can end each line with an extra '\r'.
        if (!line.empty() && line[line.size() - 1] == '\r') {
            line = line.substr(0, line.size() - 1);
        }
        if (!line.empty()) {
            return true;
        }
    }
    return false;
}

// Reads the next line and checks that it starts with keyword.
// Example: for the line "HP -2" and keyword "HP", value becomes "-2".
// Prints an error and returns false if the line is missing or wrong.
bool Adventure::readField(std::ifstream& in, const std::string& keyword, std::string& value) {
    std::string line;
    if (!nextLine(in, line)) {
        std::cout << "Error: expected a " << keyword << " line but the file ended." << std::endl;
        return false;
    }
    std::string prefix = keyword + " ";
    if (line.substr(0, prefix.size()) != prefix) {
        std::cout << "Error: expected a " << keyword << " line but found: " << line << std::endl;
        return false;
    }
    value = line.substr(prefix.size());
    return true;
}

// Adds one choice number to a path.
// extendPath("", 2) gives "2". extendPath("2-1", 3) gives "2-1-3".
std::string Adventure::extendPath(const std::string& path, int choiceNumber) const {
    if (path.empty()) {
        return std::to_string(choiceNumber);
    }
    return path + "-" + std::to_string(choiceNumber);
}

// ===================== LOADING =====================

// TODO 10: open the story file and build the tree.
//   - If the file will not open, print exactly:
//       Error: could not open file <fileName>
//     and return false.
//   - Read the START_HP line and save the number in startHp_.
//     (std::stoi turns "10" into 10.)
//   - Build the whole story with readScene. The first scene's label is "START".
//   - If anything failed, return false. Otherwise give the story to tree_.
bool Adventure::load(const std::string& fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "Error: could not open file "
                  << fileName << std::endl;
        return false;
    }
    std::string value;
    if (!readField(file, "START_HP", value)) {
        return false;
    }
    try {
        startHp_ = std::stoi(value);
    } catch (const std::exception&) {
        return false;
    }
    Scene<Moment>* firstScene = readScene(file, "START");
    if (firstScene == nullptr) {
        return false;
    }

    tree_.setRoot(firstScene);

    return true;
}

// TODO 11: read ONE scene and everything below it. Return it.
//   - Read SCENE, HP, LOOT, ITEM, and CHOICES with readField, in that order.
//   - If CHOICES is below 0 or above Scene<Moment>::MAX_CHOICES, print exactly:
//       Error: scene "<scene text>" has <n> choices. The limit is 3.
//     and return nullptr.
//   - Each choice is a LABEL line followed by a whole scene.
//   - If anything goes wrong at any depth, return nullptr
//     and make sure nothing you already built is leaked.
Scene<Moment>* Adventure::readScene(std::ifstream& in, const std::string& label) {
    std::string text, value;
    if (!readField(in, "SCENE", text)) return nullptr;

    int hpChange;
    if (!readField(in, "HP", value)) return nullptr;
    try {
        hpChange = std::stoi(value);
    } catch (const std::exception&) {
        return nullptr;
    }

    int loot;
    if (!readField(in, "LOOT", value)) return nullptr;
    try {
        loot = std::stoi(value);
    } catch (const std::exception&) {
        return nullptr;
    }

    std::string item;
    if (!readField(in, "ITEM", item)) return nullptr;

    int numChoices;
    if (!readField(in, "CHOICES", value)) return nullptr;
    try {
        numChoices = std::stoi(value);
    } catch (const std::exception&) {
        return nullptr;
    }
    if (numChoices < 0 || numChoices > Scene<Moment>::MAX_CHOICES) {
        std::cout << "Error: scene \"" << text << "\" has " << numChoices
                  << " choices. The limit is 3." << std::endl;
        return nullptr;
    }

    Scene<Moment>* scene = new Scene<Moment>(
        new Moment(text, label, hpChange, loot, item), numChoices);

    for (int i = 0; i < numChoices; ++i) {
        std::string choiceLabel;
        if (!readField(in, "LABEL", choiceLabel)) {
            delete scene;
            return nullptr;
        }
        Scene<Moment>* child = readScene(in, choiceLabel);
        if (child == nullptr) {
            delete scene;
            return nullptr;
        }
        scene->setChoice(i, child);
    }
    return scene;
}

// ===================== PLAYING =====================

// TODO 12: ask the player to pick a choice from 1 to numChoices.
//   - Print "Your choice: " (no newline) and read a whole line.
//   - If the line is not a valid number in range, print exactly:
//       Please type a number from 1 to <numChoices>.
//     and ask again.
//   - If the input ends (getline fails), return 0.
int Adventure::askChoice(int numChoices) {
    std::string input_;

    while (true) {
        std::cout << "Your choice: ";

        if (!std::getline(std::cin, input_)) {
            return 0;
        }
        try {
            int choiceNumber = std::stoi(input_);

            if (choiceNumber >= 1 && choiceNumber <= numChoices) {
                return choiceNumber;
            }
        } catch (const std::exception& e) {}

        
        std::cout << "Please type a number from 1 to " << numChoices << "." << std::endl;
    }

}

// TODO 13: play the story once from the start.
// Every time the player ENTERS a scene, in this order:
//   1. Add its HP change to hp and its loot to loot.
//   2. Print a line of 40 dashes, then the scene text.
//   3. If the scene has an item:
//        if the bag already has it, print "You already have: <item>"
//        otherwise add it to the bag and print "You picked up: <item>"
//   4. Print "HP: <hp>  Loot: <loot>" (two spaces before Loot).
//   5. If hp is 0 or less, print "Your HP hit 0. GAME OVER." and stop.
//      If the scene is an ending, print "THE END." and stop.
//   6. Print each choice as "[1] <label>" and use askChoice.
//      If askChoice returns 0, leave play right away.
// When the game stops, print:
//   Final HP: <hp>  Final loot: <loot>
//   Inventory (<count> items):
// and then print the bag.
// The bag is a List<Item>. Start with HP = startHp_ and loot = 0.
void Adventure::play() {
    int hp = startHp_;
    int loot = 0;
    List<Item> inv;

    Scene<Moment>* currentScene = tree_.getRoot();
    if (currentScene == nullptr) {
        return;
    }
    while (currentScene != nullptr) {
        Moment* m = currentScene->getData();
        if (m == nullptr) {
            break;
        }
        hp += m->getHpChange();
        loot += m->getLoot();
        std::cout << std::string(40,'-')<<std::endl; //prints the dashes
        std::cout << m->getText()<< std::endl;
        std::string item = m->getItem();
        if (!item.empty() && item != "none") {
            if (bool hasItem = inv.search(item)) {
                std::cout << "You already have " << item << " item." << std::endl;
            }
            else {
                inv.addFront(new Item(item));
                std::cout << "You picked up: " << item << std::endl;
            }
        }

        std::cout << "HP: " << hp << "  Loot:  " << loot << std::endl;

        if (hp <= 0) {
            std::cout << "Your HP hit 0. GAME OVER." << std::endl;
            break;
        }
        if (currentScene->getNumChoices() == 0) {
            std::cout << "THE END." << std::endl;
            break;
        }

        int numChoices = currentScene->getNumChoices();
        for (int i = 0; i < numChoices; ++i) {
            Scene<Moment>* child = currentScene->getChoice(i);
            std::string label = "";
            if (child && child->getData()) {
                label = child->getData()->getLabel();
            }
            std::cout << "[" << (i+1) << "] " << label << std::endl;
        }

        int choice = askChoice(numChoices);
        if (choice == 0) {
            break;
        }

        currentScene = currentScene->getChoice(choice-1);

    }
    std::cout << "Final HP: " << hp << "\n" << "Final LOOT: " << loot << std::endl;
    std::cout << "Inventory (" << inv.size() << " items)" << std::endl;
    inv.print();
}

// ===================== ANALYZING =====================

// TODO 14: print exactly three lines:
//   Scenes: <count>
//   Endings: <count>
//   Longest playthrough: <height> choices
void Adventure::printStats() const {
    std::cout << "Scenes: " << tree_.countScenes() << std::endl;
    std::cout << "Endings: " << tree_.countEndings() << std::endl;
    std::cout << "Longest Playthrough: " << tree_.height() << std::endl;
}

// TODO 15: print every ending in the story, one per line.
void Adventure::printSpoilers() const {
    printEndings(tree_.getRoot(),"");
}

// TODO 16: print every ending below scene.
// path holds the choice numbers taken to reach scene, like "2-1".
// Each ending prints as:
//   Path <path>: <scene text>
// If the very first scene is an ending, print "Path (start): <scene text>".
// Endings print in order: choice 1 before choice 2 before choice 3.
void Adventure::printEndings(Scene<Moment>* scene, const std::string& path) const {
    if (scene == nullptr) {
        return;
    }
    if (scene->isEnding()) {
        std::cout << "Path ";
        if (path.empty()) {
            std::cout << "(start)";
        }
        else {
            std::cout << path;
        }
        std::cout << ": " << *scene->getData() << std::endl;
    }
    else {
        for (int i = 0; i < scene->getNumChoices(); ++i) {
            std::string next = extendPath(path, i+1);
            printEndings(scene->getChoice(i), next);
        }
    }
}

// TODO 17: the greedy advisor.
// Start at the first scene with startHp_ and 0 loot.
// Enter scenes the same way play does (add HP and loot).
// Stop when hp is 0 or less, or you reach an ending.
// Otherwise always move to the choice with the MOST loot right now.
// On a tie, pick the lower choice number.
// Print:
//   Greedy advisor
//     Path: <path>
//     Loot: <loot>
//     Result: died               (or "Result: reached an ending")
void Adventure::greedyRun() const {
    int hp = startHp_;
    int loot = 0;
    std::string path ="";

    Scene<Moment>* currentScene = tree_.getRoot();
    if (currentScene == nullptr) {
        return;
    }
    while (currentScene != nullptr) {
        Moment* m = currentScene->getData();
        if (m == nullptr) {
            break;
        }
        hp += m->getHpChange();
        loot += m->getLoot();
        if (hp <= 0 || currentScene->isEnding()) {
            break;
        }

        int numChoices = currentScene->getNumChoices();
        if (numChoices == 0) {
            break;
        }

        int bestChoice = 0;
        int bestLoot = -1;
        bool first = true;

        for (int i = 0; i < numChoices; ++i) {
            Scene<Moment>* child = currentScene->getChoice(i);
            if (child != nullptr && child->getData() != nullptr) {
                int invLoot = child->getData()->getLoot();
                if (first || invLoot > bestLoot) {
                    bestLoot = invLoot;
                    bestChoice = i;
                    first = false;
                }
            }
        }

        path = extendPath(path, bestChoice+1);
        currentScene = currentScene->getChoice(bestChoice);
    }
    std::cout << "Greedy Advisor " << std::endl;
    std::cout << "\tPath: " << path << std::endl;
    std::cout << "\tLoot: " << loot << std::endl;

    if (hp <= 0) {
        std::cout << "\tResult: died" << std::endl;
    }
    else {
        std::cout << "\tResult: Reached an edning" << std::endl;
    }
}

// TODO 18: the best total loot you can collect from scene down to an ending,
// arriving at scene with hp health and having taken path to get here.
//   - Return -1 if every way down from here kills you.
//   - Put the path of the best run into bestPath.
//   - Must be recursive and look at every choice.
int Adventure::bestLoot(Scene<Moment>* scene, int hp, const std::string& path, std::string& bestPath) const {
    if (!scene || !scene->getData()) {
        return -1;
    }
    hp += scene->getData()->getHpChange();
    if (hp <= 0) {
        return -1;
    }

    int currentLoot = scene->getData()->getLoot();

    if (scene->isEnding()) {
        bestPath = path;
        return currentLoot;
    }

    int mostLoot = -1;
    std::string thisPath = "";

    for (int i = 0; i < scene->getNumChoices(); ++i) {
        Scene<Moment>* child = scene->getChoice(i);
        if (!child) {
            continue;
        }
        std::string nextPath = extendPath(path, i+1);
        std::string subPath = "";

        int lootSubPath = bestLoot(child, hp, nextPath, subPath);
        if (lootSubPath != -1) {
            int totLoot = lootSubPath + currentLoot;
            if (totLoot > mostLoot) {
                mostLoot = totLoot;
                bestPath = subPath;
            }
        }
    }
    return mostLoot;
}

// TODO 19: the optimal advisor. Use bestLoot from the first scene.
// Print:
//   Optimal advisor
//     Path: <path>
//     Loot: <loot>
//     Result: reached an ending
// If no path survives, print only:
//   Optimal advisor
//     Result: no path survives this story
void Adventure::optimalRun() const {
    std::string path = "";
    std::string optimalPath = "";

    int optimalLoot = bestLoot(tree_.getRoot(), startHp_, path, optimalPath);

    if (optimalLoot != -1) {
        std::cout << "Optimal Advisor" << std::endl;
        std::cout << "\tPath: " << optimalPath << std::endl;
        std::cout << "\tLoot: " << optimalLoot << std::endl;
        std::cout << "\tResult: reached an ending" << std::endl;
    } else {
        std::cout << "Optimal Advisor" << std::endl;
        std::cout << "\tResult: no path survives this story " << std::endl;
    }
}
