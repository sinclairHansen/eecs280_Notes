

//Notes for week 6
//Sinclair Hansen
// September 29, 2025
// Derived classes and inheritance
#include <iostream>
using namespace std;

class Bird {
private:
    int age; 
    string name;
public:
    Bird(const string &name_in)
: age(0), name(name_in) { //We need to initialize the variables
                //if we don't they will get 'junk'. Either here or in the private tab. 
cout << "Bird ctor" << endl;
}
string getName() const {return name;}
int getAge() const { return age; }
void haveBirthday() { ++age; }
void talk() const {
    cout << "tweet" << endl;
}
};

class Chicken : public Bird {
private:
    int roadsCrossed;
public:
    Chicken(const string &name_in)
    : Bird(name_in), roadsCrossed(0) {
        cout << "Chicken ctor" << endl;
}

void crossRoad() { ++roadsCrossed; }

void talk() const {
    cout << "bawwk" << endl;
}
};

/* Calling a base-class ctor
    - A constructor in a derived class always calls a constructor for a base class.
    - If no explicit call is made in the member initializer list, the default 
        constructor of the base is implicitly called

    Varieties of Inheritance
    - C++ offers three different varieties of inheritance: public, protected, private
    - We only conver public inheritance

    Desctructors are called whenever a class object's lifetime ends 
        (depends on storage duration)
    It gets called automatically when the object dies. So when they go out of scope.

    CTors and Dtors in derived types
    - Desctructors are the analog of constructors, called
    whel an object is destroyed.
    - When creating or destroying an object of a class with a base type,
    a constructor or destructor is used for each level of hierarchy.
    - For constructors, we get top down behavior.

    Function Overloading
        - the use of a single name to represent many functions
            within the same scope
        - This will be shown by the same function having different parameters


*/