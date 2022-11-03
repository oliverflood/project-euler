#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
	// smallest amount of prime factors that can recreate 1-20 by multiplicaton, done on paper
}

/*

There are two distinct areas of memory called the stack and the heap

Stack- limited size chunk of larger blob of system memory
Relatively small, about 8MB
If you run out of memory -> stack overflow
Allocated in contiguous block duing compile time
Known as static memory
Stores local/global variables, constants, values declared in a program's functions
Functions have their own stack frame
Functions which are called are put on the stack
No memory issues I think

Heap- comprises essentially all the rest of system memory
Heap is larger and determined by RAM and faster
Heap memory is allocated at runtime in random order
Known as dynamic memory
Allocated with pointers and the "new" operator
Dynamic memory does not disappear when the function ends as they are on the heap and not the function stack
You can run out of heap space -> heap overflow
If this happens you have to manually free (delete) heap memory after used, otherwise you'll get memory leaks

*/