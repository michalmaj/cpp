/*
 * String is plain text that represents alphanumeric data. A string comprises one or more
 * characters. A character can be a letter, number, or space.
 * Note: We consider string as text even if it contains a number. If that is so, then then how
 * can the string be distinguished from the actual code? To differentiate both, we always
 * write string data inside double-quotes.
 * 
 * An escape sequence comprises two or more characters that are used to modify the format of
 * the output. The first character in the sequence is the backslash \. The remaining character
 * determine what our escape sequence will actually do. List of escape sequences:
 * https://en.cppreference.com/w/cpp/language/escape
*/

#include <iostream>

int main(){
    // Declare and initialize a string variable
    std::string text = "Hey12345";
    
    // Display value of string variable
    std::cout << "String: " << text << std::endl;
    
    // Declare and nitialize string variable with some escape characters.
    std::string str = "Hello\nI\tam\tJohn";
    
    // Display the string
    std::cout << str << std::endl;


    return 0;
}
