/*
 * Lambda functions provide in-place functionality. The compiler gets a lot of insight and has therefore 
 * great optimization potential. Lambda functions can receive their arguments by value or by reference. They
 * can capture their environment by value, by reference, and with C++14 by move.
 *
 * Note: Lamba functions should be our first choice. If the functionality of our callable is short and
 * self-explanatory, use a lambda function. A lambda function is, in general, faster and easier to 
 * understand.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges> // -std=c++20

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "myVec contains: " << myVec << std::endl;
    
    std::ranges::for_each(myVec, [](int& i){i *= i;});
    std::cout << "myVec contains: " << myVec << std::endl;

    return 0;
}
