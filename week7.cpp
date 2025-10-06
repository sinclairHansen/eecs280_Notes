
/*
Week 7 CPP notes
Monday October 6, 2025
Sinclair Hansen


Arrays in C++
    In cpp an array is a very simple collection of objects
    arrays have a fixed size, hold elements of same type
    ́...have ordered elements.
    ...occupy a contiguous chunk of
    memory.
   ...support constant time random access.
    (i.e. “indexing”)


Array Decay
- The tendency of arrays to turn into pointers has a few consequences
You cant assign arrays to each other.

int arr1[4] = ...
int arr2[4] = ...
arr2 = arr1 // ERROR type mismatch
we need an r value and l value for assignments to work
*/

/*
POINTER ARITHMETIC
*/
#include <iostream> 
using namespace std;
int main(){
    int arr[4] = {2, 5, 4, 7};
    cout << arr; // 2 address
    cout << *arr + 2; // 4

// Array Indexing
/*
Indexing is shorthand for pointer arithmetic followed by a dereference
*/

int arr[4] = {1, 2, 3, 4};
cout << arr[3] << endl; // 4
//This is equivalent to
cout << *(arr + 3) << endl;

arr < arr + 2; // This works but the result is unspecified since it compares addresses

// [] is equivalent to *arr

// Traversal by Index

//Traversal by index
    // Keep track of an integer index variable.
    // To get an element, use the index as an offset from the beginning of the array

int const SIZE = 5;
int arr[SIZE] = {1, 2, 3, 4, 5};

for (int i = 0; i < SIZE; i++)
{
    cout << *(arr + i) << endl;
    cout << arr[1] << endl;
}
int x = sizeof(arr); // This works if the array is not decayed
int y = sizeof(*arr); // This also works


// Traversal by Pointer

int *end = arr + SIZE;
for (int *ptr = arr; ptr < end; ++ptr)
{
    cout << *ptr << endl;
}
// This just changes where the pointer is pointer to 
// Exits once the pointer reaches the last element


// Functions and Array Parameters

int maxValue(int arr[])
{
    // ...
    return 0;
}
/* This is not a pass by reference. It does not have a '&'. Instead
it is a pass by pointer. In order to pass by reference, we need to know what
the actual object is. This array is decayed. 

When we pass by value, we are passing the r value of the object.

This function is passing a pointer to the first element of the array.

The first element of the array is equivalent to int * arr. 


C-Style Strings
- In the original C language, strings are simply 
    represented as an array of characters
*/
#include <cstring>
char str1[6] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char str2[6] = "hello";
// The type of str2 is const char[6]

/*
There is a null character at the end of every string. This is represented as
'\0' in code. 

ASCII value is 0. 

Just like arrays mentioned earlier, character arrays can decay into a pointer.
*/
char *strPtr = str1;

/*
C-style strings are char arrays
    char values are just numbers underneath



*/

str1 < str2; // BAD because it is comparing addresses
str1 == "hello"; //Bad

strcmp(str1, str2) < 0; // YES

// Copy strings? 

str1 = str2; // BAD
strcpy(str1, str2); // YES

void strprint(const char *str)
{
    while (*ptr != '\0')
    {
        cout << *ptr;
        ptr++;
    }
}

// A for loop would work as well, but it may be better to do event control
// rather than iterations


/*
Containers and Data Structures
A container holds objects/data

- A container's interface defines available operations,
    eg adding, removing, looking up, modifying data.

The implementation of a container is a data structure:
    - Data representation
        Underlying storage of data in memory, eg and array
    - Representation invariants
        Intentional structure/restrictions on how data is organized.
    - Implementation
        Code to manipulate data. Rely on and maintain invariants.
    - Efficiency
        With lots of data, does it still go fast?
        Often measured by Time Complexity

SETS
- A set is an unordered container of unique elements. Assume ints for now.
*/
IntSet set; // See class below
set.insert(7);
set.insert(32);

cout << "Size: "<< set.size() << endl;
set.print(cout);

set.insert(42);
set.remove(32);

cout << "Contains 32? " << set.contains(32) << endl;
cout << "Contains 42? " << set.contains(42) << endl;

/*
Why sets?
Task: Find a list of the unique words in a Piazza Post.*
The right data structure makes the algorithm easy.
    Insert each word into a set. Return the set. Done.

*/
set<string> unique_words(const string &str) {
    istringstream source(str);
    set<string> words;
    string word;
// Read word by word from the
// stringstream and insert into the set
    while (source >> word) {
        words.insert(word);
    }
    return words;
        }
// *This code will be used in P4 to achieve the actions mentioned above
return 0;



}
// This is what the class will look like for IntSet


class IntSet {
public:
// Maximum capacity of a set.
static const int ELTS_CAPACITY = 10;
// REQUIRES: size() < ELTS_CAPACITY

// EFFECTS: adds v to the set
void insert(int v);

// EFFECTS: removes v from the set
void remove(int v);

// EFFECTS: returns whether v is in the set
bool contains(int v) const;

// EFFECTS: returns the number of elements
int size() const;

// EFFECTS: prints out the set
void print(std::ostream &os) const;
};
// These are the member function declarations. The implementation
// will be written in the .cpp file

// The const keywords means that the functions will not change IntSet

// The static key word means that the value will not be repeated every time
// an object is called. It helps save memory by only making one copy. 