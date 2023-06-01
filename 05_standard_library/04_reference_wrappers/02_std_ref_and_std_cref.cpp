/*
 * With the helper functions std::ref and std::cref we can easily create reference wrappers to variables.
 * std::ref will create a non-constant reference wrapper, std::cref a constant one.
*/
#include <iostream>
#include <functional>

void invokeMe(const std::string& s){
    std::cout << s << ": const" << std::endl; 
}

template <typename T>
void doubleMe(T t){
    t *= 2;
}

int main(){
    /*
     * So it's possible to invoke the function invokeMe, which gets a constant reference to an std::string,
     * with a non-constant std::string s, which is wrapped in a std::cref(s). If we wrap the variable i in
     * the helper function std::ref, the function template doubleMe will be invoked with a referene. So the
     * variable i will be doubled.
    */
    std::string s{"string"};
    
    invokeMe(std::cref(s)); // String
    
    int i = 1;
    std::cout << i << std::endl; // 1
    
    doubleMe(i);
    std::cout << i << std::endl; // 1
    
    doubleMe(std::ref(i));
    std::cout << i << std::endl;


    return 0;
}
