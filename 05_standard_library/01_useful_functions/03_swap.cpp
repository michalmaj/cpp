/*
 * With the function std::swap defined in the <utility> header, we can easily swap two objects.
*/
#include <iostream>

int main(){
    int var1{99};
    int var2{-1};
    
    std::cout << "Before swapping:\n";
    std::cout << "var1: " << var1 << std::endl;
    std::cout << "var2: " << var2 << std::endl;
    
    std::cout << std::endl;
    
    std::swap(var1, var2);
    
    std::cout << "After swapping:\n";
    std::cout << "var1: " << var1 << std::endl;
    std::cout << "var2: " << var2 << std::endl;

    return 0;
}
