/*
 * When our goal is to hide the unnecessary details from the users, we can divide the code into different
 * files. This is where header files come into play.
 * To hide our class, we follow a few steps. The firt step is to create a header file. Ths file will only
 * contain the declaration of the class and its members. A header file always has the .h extension.
 * In the header file, we have two commands:
 *  #ifndef CIRCLE_H
 *  #define CIRCLE_H
 * These commands tell the compiler that this header fle can be used in multiple places. The #ifndef command
 * ends with #endif
*/
#include <iostream>
#include "Circle.h"

int main(){

    Circle c(5);
    std::cout << "Area: " << c.area() << std::endl;
    std::cout << "Perimeter: " << c.perimeter() << std::endl;

    return 0;
}
