/*
 * A reference wrapper is a copy-constructible and copy-assignable wrapper for a object of type& which is
 * defined in the header <functional>. So we have an object, that behaves like a reference, but can be
 * copied. Contrary to classic references, std::reference_wrapper objects support two additional use cases:
 *  1. We can use them in containers of the Standard Template Library.
       std::vector<std::reference_wrapper<int>> myIntRefVector
 *  2. We can copy instances of classes, which have std::reference_wrapper objects. This is in general not
 *     possible with references.
 *
 * To access the reference of a std::reference_wrapper<int> myInt(1), the get method can be used: 
 * myInt.get(). We can use a reference wrapper to encapsulate and invoke a callable.
*/
#include <iostream>
#include <functional>
#include <type_traits>

void foo(){
    std::cout << "Invoked" << std::endl;
}

int main(){
    typedef void callableUnit();
    
    std::reference_wrapper<callableUnit> refWrap(foo);

    refWrap();

    return 0;
}
