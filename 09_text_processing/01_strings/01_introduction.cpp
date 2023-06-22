/*
 * A string is a sequence of characters. C++ has many methods to analyze or to change a string. C++ strings
 * are the safe replacement for C strings: const char*. Strings need the header <string>.
 * A string is similar to an std::vector containing characters. It supports a very similar interface. This
 * means that in addition to the methods of the string class, we can access the algorithms of the Standard
 * Template Library to work with the string.
 * In example below the variable std::string name has the value JohnSnow. We have used the STL algorithm 
 * std::find_if to get the upper letter aad the extract first and last name into the variables firstName and
 * lastName
*/
#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string name{"JohnSnow"};
    std::string firstName;
    std::string lastName;
    
    auto it = std::find_if(name.begin() + 1, name.end(),
                           [](char c){return std::isupper(c);});
                           
    if(it != name.end()){
        firstName = std::string(name.begin(), it);
        lastName = std::string(it, name.end());
    }
    std::cout << firstName << " " << lastName << std::endl;


    return 0;
}
