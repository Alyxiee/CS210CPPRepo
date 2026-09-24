1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.
Answer:It takes two separate calls instead of one because it is vital that the data that doomed pointed to gets
delete, and it is vital that the pointer itself is destructed. If only one or the other is deleted, that leaves
some data about either what doomed contained or doom itself lost in the memory forever. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?
Answer: The swap from T data to T* data makes a destructor necessary because C++ will automatically delete the
pointers, but the data that the pointers pointed to will not be deleted, causing a bad memory leak. The reason that
T data does NOT need a destructor is because the data is stored in the array, so when the class is destroyed
all the data is also destroyed. This doesn't happen with T* data. You would not get a compiler error because it is
technically not "wrong" to not have a destructor coded, it will just be a really terrible problem later.

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?
Answer: search() is never allowed to delete ownership, and addFront() is. search() looks at the address, and
addFront() looks at the value within T*

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?
Answer: The first is polymorphism, because LinkedList and ArrayList share a base. The second I think is
patterning because the makeList() hides detail from main.cpp, so it can use whatever.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
Answer: Override. I thought that overriding might be inherent with the declaration of a function with the same name,
but it does not seem to be, and it needs to be declared as overridden. Leaving out overriding in any of the functions
that use it would lead to the incorrect function being called and thus everything breaking, it's OVER.