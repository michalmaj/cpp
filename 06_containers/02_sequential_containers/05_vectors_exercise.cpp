/*
 * Create an std::vector and determine its siez and capacity before and after a call to shrink_to_fit
*/
#include <iostream>
#include <vector>

int main(){
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::cout << "Size and capacity before shrink_to_fit:\n";
    std::cout << "vec.size(): " << vec.size() << std::endl;
    std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
    
    vec.shrink_to_fit();
    
    std::cout << "Size and capacity after shrink_to_fit:\n";
    std::cout << "vec.size(): " << vec.size() << std::endl;
    std::cout << "vec.capacity(): " << vec.capacity() << std::endl;

    return 0;
}
