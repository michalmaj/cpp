/*
 * Strings support the well-known comparison operators ==, !=, <, >, >=, <=. The compariso of two strings
 * takes place on their elements.
 *
 * The + operator is only overloaded for C++ strings. The C++ type system permits concatenation of C++ and C
 * strings into C++ strings, but not concatenation of C++ and C strings into C strings. The reason is that
 * the + operator is overloaded for C++ strings:
 *  std::string wrong= "1" + "1"; // ERROR
 *  std::string right= std::string("1") + "1"; // 11
*/
#include <iostream>
#include <string>

int main(){
    std::cout << std::boolalpha;

    std::string first{"aaa"};
    std::string second{"aaaa"};
    
    std::cout << "first < first: " << (first < first) << std::endl;
    std::cout << "first <= first: " << (first <= first) << std::endl;
    std::cout << "first < second: " << (first < second) << std::endl;
    
    std::cout << std::endl;
    
    std::string one{"1"};
    std::string oneOneOne = one + std::string("1") + "1";
    
    std::cout << "1 + 1 + 1: " << oneOneOne << std::endl;

    return 0;
}
