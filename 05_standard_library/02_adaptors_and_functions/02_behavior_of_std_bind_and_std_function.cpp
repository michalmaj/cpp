/*
 * std::bin
 * Because of std::bind, you can create function objects in a variety of ways:
 *  - bind the arguments to an arbitary position,
 *  - change the order of the arguments,
 *  - intoduce plceholder for arguments,
 *  - prtial evaluate functions,
 *  - invoke the newly created function objects, use them in the algorithm of the STL or store them in
 *    std::function.
 *
 * std::function
 * std::function can store arbitrary callables in variables. It's kind of polymorphic function wrapper. A
 * callable may be a lambda, a function object, or a function. std::function is always necessary and can't 
 * be replaced by auto, if you have to specify the type of the callable explicitly.
*/
#include <iostream>
#include <map>
#include <functional>

int main(){
    std::map<const char, std::function<double(double, double)>> tab;
    
    tab.insert(std::make_pair('+', [](double a, double b){return a + b;}));
    tab.insert(std::make_pair('-', [](double a, double b){return a - b;}));
    tab.insert(std::make_pair('*', [](double a, double b){return a * b;}));
    tab.insert(std::make_pair('/', [](double a, double b){return a / b;}));
    
    std::cout << "3.5 + 4.5 = " << tab['+'](3.5, 4.5) << "\n";
    std::cout << "3.5 - 4.5 = " << tab['-'](3.5, 4.5) << "\n";
    std::cout << "3.5 * 4.5 = " << tab['*'](3.5, 4.5) << "\n";
    std::cout << "3.5 / 4.5 = " << tab['/'](3.5, 4.5) << "\n";

    return 0;
}
