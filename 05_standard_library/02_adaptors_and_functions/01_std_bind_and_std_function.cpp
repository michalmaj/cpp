/*
 * The two functions std::bin and std::functions fit very well together. While std::bind enables you to 
 * create new function objects on the fly, std::function takes these temporary function objects and binds
 * them to a variable. Both functions are powerful tools from functional programming and need the header
 * <functional>.
 *
 * std::bin, and std::function are mostly superfluous
 * Both, which where part of Technical Report 1 (TR1), are mostly not neccessary any more with C++11. We can
 * use lambda functions instead os std:::bind and most often we can use the automatic type deduction instead
 * of std::function.
*/
#include <iostream>
#include <functional>


double divMe(double a, double b) {return a / b;}

int main(){
    std::cout << std::boolalpha;
    std::function<double(double, double)> myDiv1 = std::bind(divMe, 
                                                   std::placeholders::_1, std::placeholders::_2);
    std::function<double(double)> myDiv2 = std::bind(divMe, 2000, std::placeholders::_1);
    
    std::cout << (divMe(2000, 10) == myDiv1(2000, 10)) << "\n";  
    std::cout << (myDiv1(2000, 10) == myDiv2(10)) << "\n"; 
                                                 



    return 0;
}
