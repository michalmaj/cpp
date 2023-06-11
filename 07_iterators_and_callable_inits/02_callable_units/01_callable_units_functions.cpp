/*
 * Introduction
 * Many of STL algorithms and containers can be parametrized with callable units or short callables. A 
 * callable is something that behaves like a function. Not only are these functions but also function 
 * objects and lambda functions. Predicates are special functions that return a boolean as the result. If a
 * predicate has onr argument, it's called a unary predicate if a predicate has two arguments, it's called
 * a binary predicate. The same holds for functions. A function taking one argument is a unary function; a
 * function taking two arguments is a binary function.
 *
 * Note: To change the elements of a container, our algorithms must get them by reference. Callables can
 * recive their arguments by value or by reference from their container. To modify the elements of the 
 * container, they must address them directly, so it s necessaty that the callable gets them by reference.
 *
 * Functions
 * Functions are the simples callables. They can have - apart from static variables - no state. Because the
 * defintion of a function is often widely separated from its use or even in a different translation unit,
 * the compiler has fewer opportunities to optimize the resulting code.
*/
#include <iostream>
#include <algorithm>
#include <vector>

void square(int& i){
    i *= i;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "myVec contains: " << myVec << std::endl;
    
    std::for_each(myVec.begin(), myVec.end(), square);
    std::cout << "myVec contains: " << myVec << std::endl;


    return 0;
}
