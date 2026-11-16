1. For every function you wrote (TODO 1 to 19), explain in your own words what it does and
   give its time complexity in terms of n, the number of scenes. One short paragraph each.
TODO 1 — Scene constructor. It stores a scene’s data and creates exactly one pointer slot per choice. The opening scene has three slots, while the [Panic] ending has none. A scene has at most three choices, so this takes O(1) time.
TODO 2 - Scene destructor. It deletes each child scene, its own Moment, and then its choice-slot array. The children also delete their descendants. Deleting a scene and its entire subtree takes O(n) time in the worst case.
TODO 3 - isEnding. It checks whether the scene has zero choices. Both [Fight Back] and [Panic] lead to ending scenes, though they end very differently. This takes O(1) time.
TODO 4 - getChoice. It returns the scene in a numbered slot, or nullptr if the index is outside the valid range. Looking up the opening scene’s [Panic] branch takes O(1) time.
TODO 5 - setChoice. It connects a child scene to a valid choice slot. Filling an empty slot during loading takes O(1) time. If a slot already holds a subtree, my code deletes that subtree first, which could take O(n) time.
TODO 6 - countScenes. It counts the current scene and recursively counts every child, including endings. It visits each scene once, so it takes O(n) time.
TODO 7 - countEndings. It returns one for a scene with no choices and otherwise adds the results from its children. It finds the eight endings in my story in O(n) time.
TODO 8 - height. It checks each child’s height and keeps the longest route to an ending. My story’s longest routes take five choices from the opening scene. The function visits each scene once, taking O(n) time.
TODO 9 - clear. It deletes the root and sets the root pointer to nullptr. Because the scene destructor handles all descendants, clearing the full story takes O(n) time.
TODO 10 - load. It opens my_story.txt, reads the starting HP of 10, builds the story beginning at START, and gives the root to the tree. Building all the scenes takes O(n) time, aside from the lengths of the text lines.
TODO 11 - readScene. It reads a scene’s text, HP change, loot, item, and choice count. It then reads each choice label and recursively builds the scene behind it. Reading the whole story takes O(n) time; if a child fails to load, it deletes the scenes already built below that point.
TODO 12 - askChoice. It reads a whole input line and asks again until the player enters a number within the current scene’s choice range. One attempt takes O(1) time in terms of scenes. The total depends on how many invalid answers the player enters.
TODO 13 - play. It follows the player’s choices, applies each scene’s HP and loot, handles items, and stops on death or an ending. It can visit at most (n) scenes. Since searching an inventory can get slower as items accumulate, its worst-case time is O(n²) if many scenes give items.
TODO 14 - printStats. It prints the scene count, ending count, and longest path. Those are three separate tree traversals, but the total is still O(n).
TODO 15 - printSpoilers. It starts the ending printer at the root with an empty path. Visiting the scenes takes O(n) time, though copying long path strings can add work in a much deeper story.
TODO 16 - printEndings. It follows choices in order and prints each ending with a path such as 2-2-2-1 for [Fight Back]. It visits every scene once, so the traversal is O(n). In a very deep tree, repeatedly copying the path string can make the full cost O(n²).
TODO 17 - greedyRun. It follows one route, always choosing the next scene with the most immediate loot. It checks at most three children per step, so it takes O(n) time in the worst case.
TODO 18 - bestLoot. It recursively considers every child, rejects routes where HP reaches zero, and keeps the greatest loot total from a surviving ending. Its tree traversal is O(n). Copying path strings can add extra work, up to O(n²) in a very deep story.
TODO 19 - optimalRun. It calls bestLoot with the root and 10 starting HP, then prints the best surviving result. Its tree traversal is O(n), with the same possible path-string copying cost.
2. Why does each scene allocate exactly numChoices slots instead of declaring Scene<T>*
   choices[3]? What does an ending hold in choices_, and why?
Each scene only needs slots for its real choices. The opening scene has three: UNCP?, Who are you?, and [Panic]. The scene asking “There are others like me?” has two. An ending such as [Fight Back] has zero, so its choices_ remains nullptr and no slot array is allocated. A fixed three-pointer array in every scene would reserve unused slots, especially across my eight endings.
3. Walk through your Scene destructor. What gets deleted, and in what order? What would
   go wrong if choices_ were deleted first?
The destructor first deletes the scene pointers in its choice slots. Each child’s destructor does the same, so the deletion works down to the endings. It then deletes the current scene’s Moment and finally deletes the array holding its choice pointers. If the array were deleted first, the destructor could no longer safely read those pointers to delete the children. That would leave scenes allocated and make any later access to the freed array invalid.
4. Show the path greedy took and the path optimal took on your story, with the loot for each.
   Explain why greedy lost. If greedy did not lose, change your story until it does, and explain
   what you changed.
   Greedy takes 1-1-1: UNCP? → There are others like me? → Are there any other humans left?. It gains 3 loot for Curiosity and 1 in the final scene, for 4 loot. That last scene changes HP by −10, taking the player from 10 to 0, so greedy dies.

The optimal surviving path is 2-2-2-1: Who are you? → ..Neural..? → No. I don't like this at all! → [Fight Back]. The last two scenes give 2 and 5 loot, for 7 loot total. Their HP changes are −3 and −4, so the player reaches that ending with 3 HP.

Greedy loses because all three choices at the start offer 0 immediate loot, so its tie rule picks the first one. Later, Are there any other humans left? offers 1 loot, while This isn't right offers 0, so greedy picks the fatal scene. Looking farther ahead would show that [Fight Back] gives a better surviving result. My story already makes greedy lose; I did not change it.
5. bestLoot tries every path, yet it runs in O(n) time. Explain why it is not exponential, using
   what you know about paths and leaves in a tree.
   bestLoot explores every route, but the routes are branches of one tree containing (n) scenes. It visits a child subtree once and does not restart from the beginning for each ending. Every ending is a scene, so there cannot be more endings than scenes. That makes the scene traversal O(n). The distinction is that copying the path strings can take additional time; it does not mean the function revisits an exponential number of scenes.
6. Which List methods does your game use, and why? What does one search cost as the bag
   grows?
   The inventory is a List<Item>. In play, search(item) checks whether the bag already contains an item, and addFront(new Item(item)) adds a new one. At the end, size() supplies the inventory count and print() displays it. On my story’s routes, items include Curiosity, Strength, A Will Of Your Own, and Freedom. If search walks the List one item at a time, one search costs O(b) for a bag of (b) items: it may need to check every item as the bag grows.



