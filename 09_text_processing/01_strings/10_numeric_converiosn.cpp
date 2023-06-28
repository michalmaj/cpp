/*
 * We can convert numbers or floating point numbers to correspondng std::string or std::wstring with 
 * std::to_string(val) and std::to_wstring(val).
 * The inverse of the mentioned (for the numbers of floating point numbers) can be achieved through a 
 * fucntion family sto* functions. All functions need the header <string>.
 * 
 * Read sto* as 'string to'. The seven ways to convert a strng into a natural or floating point number 
 * follow a simple pattern. All functions start with sto and add further characters, denoting the type to 
 * which the strings should be converted. For example, stol stands for 'string to long' or stod 'string to 
 * double'.
 *
 * The sto functions all have the same interface:
 * 	std::stol(str, idx=nullptr, base=10);
 * The function takes a strnig and determines the lng representation of the base (base param). stol ignores 
 * leading spaces and optionally returns the index of the first valied character in idx. By default, the 
 * base is 10. Valid values for the base are 0 and 2 through 36. If we use base 0, the compiler 
 * automatically determines the type based on the format of the string. If the base is bigger than 10, the 
 * compiler encodes them in the characters a to z. The representation is analogous to the representation of
 * hexadecimal numbers. 
 *
 * The tables gives an overview of all functions:
 *  Method                              Description
 *  std::to_strinf(val)                 Converts val into a std::string.
 *  std::to_wstring(val)                Converts val into a std::wstring.
 *  std::stoi(str)                      Returns an int value.
 *  std::stol(str)                      Returns a long value.
 *  std::stoll(str)                     Returns a long long value.
 *  std::stoul(str)                     Returns an unsigned long value.
 *  std::stoull(str)                    Returns an unsigned long long value.
 *  std::stof(str)                      Returns a float value.
 *  std::stod(str)                      Returns a double value.
 *  std::stold(str)                     Returns an long double value.
 *
 * The functions throw an std::invalid_arument exception if the conversion is not possible. If the 
 * determined value is too big for the destination type, we get an std::out_of_range exception.
 */
#include <iostream>
#include <limits>
#include <string>
#include <exception>

int main(){
    std::cout << "to_string, to_wstring\n";
    
    std::string maxLongLongString = std::to_string(std::numeric_limits<long long>::max());
    std::wstring maxLongLongWstring = std::to_wstring(std::numeric_limits<long long>::max());
    
    std::cout << std::numeric_limits<long long>::max() << std::endl;
    std::cout << maxLongLongString << std::endl;
    std::wcout << maxLongLongWstring << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "sto*\n";
    
    std::string str{"10010101"};
    
    std::cout << std::stoi(str) << std::endl;
    std::cout << std::stoi(str, nullptr, 16) << std::endl;
    std::cout << std::stoi(str, nullptr, 8) << std::endl;
    std::cout << std::stoi(str, nullptr, 2) << std::endl; 
        
    std::cout << std::endl;
    
    size_t idx;
    std::cout << std::stod(" 3.5 km", &idx) << std::endl;
    std::cout << "Not numeric char at position " << idx << "." << std::endl;
    
    std::cout << std::endl;
    
    try{
        std::cout << std::stoi("    3.5 km") << std::endl;
        std::cout << std::stoi("    3.5 km", nullptr, 2) << std::endl;
    }catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }


    return 0;
}
