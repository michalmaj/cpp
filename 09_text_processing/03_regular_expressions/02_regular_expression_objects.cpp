/*
 * The type of the text determines the character type of the regular expression, the type of search result, 
 * and the type of action with the search result.
 *
 * The following table shows the four different combnations of type of text, regular expression, search
 * result and action:
 *  Text type           Regular Expression type         Result tupe         Action type
 *  chant char*         std::regex                      std::smatch         std::regex_search
 *  std::string         std::regex                      std::smatch         std::regex_search
 *  const wchar_t*      std::wregex                     std::wcmatch        std::wregex_search
 *  std::wstring        std::wregex                     std::wsmatch        std::wregex_search
 *
 * Objects of type regular expression are instances of the class template:
 *  template <class charT, class traits=regex_traits<charT>> class basic_regex
 * parametrized by their character type and traits class. The traits class defines the interpretation of the
 * properties of the regular grammar. There are two type synonyms in C++.
 *
 * We can further customise the object of type regular expression. Therefore we can specify the used grammar
 * or adapt the syntax. As said before, C++ supports the basic, extended, akw, grep, and egrep grammars. A
 * reguar expression qualified by the std::regex_constantsLLicase flag is case insensitive. If we want to
 * adopt the syntax, we have to specify the grammat explicitly.
*/
#include <iostream>
#include <regex>
#include <string>

int main(){
    std::string theQuestion{"C++ or c++, that's the question."};
    
    // Regular expression for c++
    std::string regExprStr{R"(c\+\+)"};
    
    // Regular expression object
    std::regex rgx(regExprStr);
    
    // Search result holder
    std::smatch smatch;
    
    std::cout << theQuestion << std::endl;
    
    // Looking for a partial match (case sensitive)
    if(std::regex_search(theQuestion, smatch, rgx)){
        std::cout << std::endl;
        std::cout << "The answer is case sensitive: " << smatch[0] << std::endl;
    }
    
    // Regular expression object (case insensitive)
    std::regex rgxIn(regExprStr, std::regex_constants::ECMAScript | std::regex_constants::icase);
    
    // Looking for a partial match (case insensitive)
    if(std::regex_search(theQuestion, smatch, rgxIn)){
        std::cout << std::endl;
        std::cout << "The answer is case insensitive: " << smatch[0] << std::endl;
    }

    return 0;
}
