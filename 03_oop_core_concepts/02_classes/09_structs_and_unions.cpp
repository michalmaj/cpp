/*
 * Structures
 * A structure in C++ is a group of data elements grouped together under one name. These data elements, 
 * known as members, can be of different types and sizes. It is a user-defined data type that allows us to
 * combine data items of different kinds.
 * Structs are almost identical to classes. The default access specifiers for a struct is public instead of
 * private. The default inheritance specifier is public instead of private. Structs should be used instead
 * of classes if the data type is a simple data holder.
 *
 * Unions
 * A union is a pecial data type where all members start at the same address. A union can only hold one
 * type at a time, therefore, we can save memory. A tagged union is a union that keeps track of its types.
 * By using union, we are actually pointing to the same memory for the different data types used.
 * Unions are special class types with own rules:
 *  - Only one member can exist at any ono point in time.
 *  - They only need as much space as the biggest member requires, which saves memory.
 *  - They access specifier is public by default.
 *  - They cannot have virtual methods like with inheritance.
 *  - They cannot have references.
 *  - They cannont be inherited nor inherited from.
*/
#include <iostream>

struct Person{
    int age;
    int size;
    int weight;
    std::string name;
};

union Value{
    int i;
    double d;
};

int main(){
    Value v{123}; // now v holds an int
    std::cout << v.i << "\n";
    v.d = 987.654; // now v holds a double
    std::cout << v.d << "\n";
    



    return 0;
}
