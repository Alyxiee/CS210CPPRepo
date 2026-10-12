1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

Different types of lists are formatted differently. Concat needs to work with only the same type otherwise
it would be like trying to put a square in the circle shaped hole. Just incompatible. Crashes everywhere.


2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

Previous, current, and next are the three live pointers. Current is for, well, the current node, and selection.
Losing track of current means losing your spot in the list. Losing track of previous means not being able to actually
reverse the list. And losing track of next means not being able to traverse the list at all.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

addAnywhere's bounds are `[0,size_]`, and deleteAnywhere's bounds are `[0,size_-1]`. Both functions will
promptly return and print an error message.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

concat needs to walk to the end of the list first because we do not have a tail pointer. If we did
track a tail pointer, the time complexity would be O(n), which is not ideal. I'd have to update the rest of the methods
that add anything to the list, because they would need to use the tail pointer.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

addAnywhere, everything needs to shift left. This is because shifting to the right would overwrite the next value
and essentially wipe it before ever shifting it.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

tableOne->reverse() is the line in main that actually reverses the play order. If this didn't exist, visually,
the players would be very confused. Data could possibly be lost as well.