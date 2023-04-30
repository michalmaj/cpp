/*
 * We can use comments for the documentation of our programs
 * and to help other people understand our code. 
 * 
 * In C++, we can add two types of comments:
 *  - Single-line comments;
 *  - Multi-line comments.
*/

#include <iostream>

int main(){

    // I am single-line commnet.
    // Compiler will igneore me.
    std::cout << "Single-line comments!" << std::endl;

    /*I am a multi-line commnet.
    Compiler also will ignore me!*/    
    std::cout << "Multi-line comments!" << std::endl;

    return 0;
}
