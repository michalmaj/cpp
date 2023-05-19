/*
 * Member functions define the behaviour of the class.
 * These functions can either alter the content of the data variables or use their values to perform a
 * certain omputation. Typically, member functions are declared as public, although, some functions which
 * do not need to be accessed from the outside could be kept private.
 * Like all functions, member functions can either be defined straightaway, or they could be declared first
 * and defied later. 
 * The scope resolution operator (::) allows us to simply declare the member functions in the class and 
 * define them elsewhere in the code.
 * The :: operator tells the compiler that the particular function belongs to the class preceding it.
 * 
 * Get and set functions
 * These two types of functions are very popular in OOP. A get function retrieves the value of a particular
 * data member, whereas a set function sets its value.
 *
 * Member functions can be overloaded just like any other function. Ths means that multiple member
 * functions can exist with the same name on the same scope, but must have different arguments.
*/
#include <iostream>

class Rectangle{
    int length;
    int width;
    
public:
    // Declaration
    
    // Get and set for length
    void setLength(int l); // This function changes the value of length
    int getLength(); // This function returns th value of length
    
    // Get and set for width
    void setWidth(int w); // This function changes the value of width
    int getWidth(); // This function returns th value of width
    

    
    // Declaration and definition
    int area(){ // This function calculates the area of the rectangle
        return length * width;
}
};

// It can be somewhwere elese in the code
void Rectangle::setLength(int l){
    length = l;
}

int Rectangle::getLength(){
    return length;
}

void Rectangle::setWidth(int w){
    width = w;
}

int Rectangle::getWidth(){
    return width;
}

int main(){



    return 0;
}
