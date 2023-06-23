/*
 * While the conversion of a C string in a C++ string is done implicitly, we must explicitly request 
 * conversion from a C++ string into a C string. str.copy() copies the content of a C++ string without the 
 * terminating \0 character. str.data() and str.c_str() include the terminating null character.
 *
 * Note: be careful with str.data() and str.c_str(). The return value of the two methods str.data() and 
 * str.c_str() becomes invalid if str is modiifed.
*/
#include <iostream>
#include <string>

int main(){
    std::string str{"C++ String"};
    std::cout << "str: " << str << std::endl;
    str += " C String";
    std::cout << "str: " << str << std::endl;
    
    const char* cString = str.c_str();
    std::cout << "cString: " << cString << std::endl;
    
    char buffer[10];
    str.copy(buffer, 10);
    std::cout << "buffer: " << buffer << std::endl;
    
    std::cout << std::endl;
    
    str += "works";
    std::cout << "str: " << str << std::endl;
    std::cout << "cString: " << cString << std::endl;
    std::cout << "buffer: " << buffer << std::endl;
    
    const char* cString2= cString; 

    std::string str2(buffer, buffer+10);
    std::cout << str2 << std::endl;
        
        
    return 0;
}
