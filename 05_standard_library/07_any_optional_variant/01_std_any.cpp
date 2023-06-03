/*
 * C++17 allows us to put our value in a safe container which can be accessed only when its type is 
 * specified.
 * The new C++17 data type std::any, std::optional, and std::variant are all based on the Boost Library.
 *
 * std::any is a type-safe container for single values of any type which is copy-construible. There are a
 * few ways to create a std::any container. We can use the various constructors of the factory function
 * std::make_any. By using any.emplace, we directly construct one value into any. any.reset lets us destroy
 * the contained object. If we want to know whether the container any has a value, use the method 
 * any.has_value. We can even get the typeod of the container object via any.type. Thanks to generic 
 * function std::any_cast we have access to the contained object. If we specify the wrong type, we will get
 * a std::bad_any_cast exception.
 *
 * The string represetation of the typeid is implementation defined. If anyVec.at(1) of type int the 
 * expression anVec.at(1).type().name() will return i with the GCC C++ copiler and int with the MSC.
 *
*/
#include <any>
#include <vector>
#include <iostream>

struct MyClass{};

int main(){
    std::vector<std::any> anyVec{true, 2023, std::string("World"), 3.14, MyClass()};
    
    std::cout << std::boolalpha;
    
    std::cout << "std::any_cast<bool>(anyVec.at(0)): " 
    << std::any_cast<bool>(anyVec.at(0)) << std::endl;
    
    auto myInt = std::any_cast<int>(anyVec.at(1));
    std::cout << "myInt: " << myInt << std::endl;

    std::cout << "anyVec.at(0).type().name(): " << anyVec.at(0).type().name() << std::endl; // b
    std::cout << "anyVec.at(1).type().name(): " << anyVec.at(1).type().name() << std::endl; // i
     

    return 0;
}
