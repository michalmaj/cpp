/*
 * Access to the elements of a string str is very convenient because the strings support random access 
 * iterators. We can access with str.front() the first character and wth str.back() the last character of 
 * the string . With str[n] and str.at(n) we get the n-th element by index. In the first case method returns
 * the n-th character of string. The string boundaries will not be checked. In the second case .at(n) will
 * check the strin boundaries. If the boundaries are violated a std::out_of_range exception is thrown.
 * 
 * Example:
 * It is a particulary interesting to see in the example that the copiler performs the invocation str[10].
 * The access outside the string boundaries is undefined behavior. In contrast, the C++ runtime throws an
 * std::out_of_range exception for the call str.at(10).
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>

int main(){
    std::string str= {"0123456789"};
    std::cout << "str.front(): " << str.front() << std::endl;
    std::cout << "str.back(): " << str.back() << std::endl;
    
    for(int i=0; i <=10; ++i)
        std::cout << "str[" << i << "]: " << str[i] << std::endl;
        
    try{
        str.at(10);
    }catch(std::exception& e){ // We can also use: const std::out_of_range& e
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;

    std::cout << "*(&str[0]+5): " << *(&str[0]+5) << std::endl;
    std::cout << "*(&str[5]): " << *(&str[5]) << std::endl;
    std::cout << "str[5] : " << str[5] << std::endl;


    return 0;
}
