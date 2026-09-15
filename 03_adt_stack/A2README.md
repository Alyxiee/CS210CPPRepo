## Reflection Questions

1. `topIndex` immediately holds the value of `-1` upon construction.
This is because it makes it much easier to determine `isEmpty()`.
Because `-1` obviously isn't a possible index number.
Thus, when `isEmpty()` is run, it simply checks if `topIndex` is `-1`.
This would occur both if data starts empty or if someone pops all values.
Return `true` if `topIndex == -1`, return `false` otherwise.
2. My `push()` function first checks if the `data` is full
using `isFull()`. If it isn't full, it then increments `topIndex`
so that it points to the next available spot. Then, it sets `data[topIndex]`
to `value` provided by the user. Incrementing `topIndex` last would break the stack
because if the stack were empty, the compiler would catch an out-of-bounds
exception. If the stack weren't empty, it would overwrite the previously pushed value.
3. ALL of my functions run at `O(1)`. This is because there are no loops
and there are no checks or functions dependent on the size of the
stack itself: 
- `push()` runs one check, increment, and assignment.
- `pop()` does one check and decrement.
- `peek()` one check and array access.
- `isEmpty()` does one comparison.
- `isFull()` does one comparison.
- `size()` is one addition.

    All this results in a `O(1)` runtime

4. `push()` does nothing when the stack is full.
All that happens is a print to the console saying `Stack is full`.
Nothing gets returned and `topIndex` remains the same. I chose this behavior because it
took less time, and it also just makes sense to me.
If you have a pile of pancakes, and you want to add one more but can't,
do you get rid of any of the pancakes already on your plate? No,
you just don't add another pancake.
5. `pop()` and `peek()` both produce the same message to the console as each other:
`Stack is empty`. This is because nothing happens to the stack when it is full.
Nothing changes. `peek()` will return `-1` alongside the message, however.
6. Because nothing is dependent on stack size, it would cost nothing
in time complexity. Everything will remain `O(1)`. The thing that would
change in the class field is the `private` value `data`. Instead of `data[100]`, it could
be `data[200]`, so on and so forth.

7. If this were a linked list instead of an array, we could know
all the values of the list and their position instead of just the top value
of the array. The only downside I foresee is the time complexity.
It would increase as the pointers may have to traverse the list to find the
desired value or values.












