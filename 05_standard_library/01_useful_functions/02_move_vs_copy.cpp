/*
 * The function std::move, defined in the header <utility>, empowers the compiler to move its resource. In
 * the so-called move semantic, the values from the source object are moved to the new object. Afterward,
 * the source is in a well-defined but not specifed state. Most of the times that is the default state of
 * the source. By using std::move, the compiler converts the source arg to a rvalue reference:
 *  static_cast<std::remove_reference><decltype(arg)::type&&>(arg)
 *
 * The subtle difference is that if we create a new object based on an existing one, the copy semantic will
 * copy the elements of the existing resource, whereas the move scemantic will move the elements of the
 * resource. So, of cpurse, copying is expensive and moving is cheap. But there are additional serious 
 * consequences:
 *  1. With the copy semantic, it is possible that a std::bad_allock will be thrown because our program is
 *     out of memory.
 *  2. The source of the move operations is in a "valid but unspecified state" afterward.
 *
 * To move is cheaper than to copy
 * The move scemantic has two adventages. Frstly, it is ofte a good idea to se cheap moving instead of
 * expensive copyng. So there is no superfluous allocation and deallocation of memory necessary. Secondly,
 * there are objects, which can't be copied, e.g., a thread or a lock.
*/
#include <iostream>
#include <utility>

int main(){
    std::string s1{"abcd"};
    std::string s2{"efgh"};
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    
    std::cout << std::endl;
    
    // Copying
    s2 = s1; // copy scemantic
    std::cout << "After copying:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::cout << std::endl;
    
    s1 = "abcd";
    s2 = "efgh";
    
    // Moving
    s2 = std::move(s1);
    std::cout << "After moving:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    return 0;
}
