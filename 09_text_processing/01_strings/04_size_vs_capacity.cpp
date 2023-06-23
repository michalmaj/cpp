/*
 * The number of elements a string has (str,size()) is in general smaller than the number of elements for
 * which space is reserved: str.capacity(). Therefore if we add elements to a string, new memory will not
 * necessarily be allocated. std::max_size() return the maximum amount of elements a string can have. For 
 * the three methods the following relation hold: str.size() <= str.capacity() <= str.max_size().
 *
 * The following methods dealing with memory management of strings:
 *  Methods                                     Description
 *  str.empty()                                 Checks if str has elements.
 *  str.size(), str.length()                    Number of elements of the str.
 *  str.capacity()                              Number of elements str can have without rellocation.
 *  str.max_size()                              Nuber of elements str can maximal have.
 *  str.resize(n)                               Changes str to n elements.
 *  str.reserve(n)                              Reserves memory for at least n elements.
 *  str.shrink_to_fit()                         Adjust the capacity of the string to it's size. 
*/
#include <iostream>
#include <string>

void showStringInfo(const std::string& s){
    std::cout << "s contains: " << s << std::endl;
    std::cout << "s.size(): " << s.size() << std::endl;
    std::cout << "s.capacity(): " << s.capacity() << std::endl;
    std::cout << "s.max_size(): " << s.max_size() << std::endl;
    std::cout << std::endl;
}

int main(){
    std::string str;
    showStringInfo(str);
    
    str += "12345";
    showStringInfo(str);
    
    str.resize(30);
    showStringInfo(str);
    
    str.reserve(1000);
    showStringInfo(str);
    
    str.shrink_to_fit();
    showStringInfo(str);



    return 0;
}
