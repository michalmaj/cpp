/*
 * C++ gives us a lot of freedom in selecting the data of a data member. We can choose any of the in-built
 * types such as int, double etc. Arrays, vectors, and pointers can also be used.
 * Data members should be defined as private.
 * Note: Objects of other classes as data members is another feature which adds to the flexibility of
 * classes. We can use an object from our own class as a data member in our other classes.
*/
#include <iostream>

class myClass{
    // All private members
    std::string name;
    int age;
    std::string* address;
    // We should always be careful with arrays inside classes. We should have appropriate checks in place
    // to make sure our program never goes out of bounds due to an array. A good practice is to store the
    // size of the array in a variable. Whis way, we'll always remember the maximum capacity.
    char grades[10]; // A student can have a maximum of 10 grades
};

int main(){


    return 0;
}
