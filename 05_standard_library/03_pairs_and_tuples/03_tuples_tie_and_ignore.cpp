/*
 * std::tie enables us to create tuples, whose elements reference variables. With std::ignore we can 
 * explicitly ignore elements of the tuple.
*/
#include <iostream>
#include <tuple>

int main(){
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;

    std::cout << first << " " << second << " " << third << " " << fourth << "\n"; // 1 2 3 4

    auto t = std::tie(first, second, third, fourth) // Bind the tuple
    = std::make_tuple(101, 102, 103, 104); // Create the tuple and assign it
    
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t)
    << " " << std::get<3>(t) << std::endl; // 101 102 103 104

    // Original values also changed
    std::cout << first << " " << second << " " << third << " " << fourth << "\n"; // 101 102 103 104
    
    first = 201;
    std::get<1>(t) = 202;
    
    std::cout << std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t)
    << " " << std::get<3>(t) << std::endl; // 201 202 103 104
    
    std::cout << first << " " << second << " " << third << " " << fourth << "\n"; // 201 202 103 104
    
    int a, b;
    // Get second and fourth element from tuple t
    std::tie(std::ignore, a, std::ignore, b) = t;
    std::cout << a << " " << b << std::endl; // 202 103

    return 0;
}
