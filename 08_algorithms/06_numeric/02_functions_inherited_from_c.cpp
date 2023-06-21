/*
 * As C++ evelved from C, many of the functions have been passed down to the new language.
 * C++ inherited many numeric function from C. They need the header <cmath>:
 *  https://en.cppreference.com/w/cpp/header/cmath
 * Additionally, C++ inherits further mathematical functions fromC. They are defined in the header 
 * <cstdlib>:
 *  https://en.cppreference.com/w/cpp/header/cstdlib
*/
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

int main(){
    std::cout << "cmath" << std::endl;
    
    std::cout << "std::pow(2, 10): " << std::pow(2, 10) << std::endl;
    std::cout << "std::pow(2, 0.5): " << std::pow(2, 0.5) << std::endl;
    std::cout << "std::exp(1): " << std::exp(1) << std::endl;
    std::cout << "std::ceil(5.5): " << std::ceil(5.5) << std::endl;
    std::cout << "std::floor(5.5): " << std::floor(5.5) << std::endl;
    std::cout << "std::fmod(5.5, 2): " << std::fmod(5.5, 2) << std::endl;
    
    double intPart;
    auto fracPart = std::modf(5.7, &intPart);
    std::cout << "fmod(5.7, &intPart): " << intPart << " + " << fracPart << std::endl;
    
    std::cout << "\ncstdlib: " << "\n\n";
    std::div_t divresult = std::div(14, 5);
    std::cout << "std::div(14, 5): " << divresult.quot << " remainder " << divresult.rem << std::endl;
    
    std::cout << std::endl;
    
    // seed
    std::srand(time(nullptr));
    for(int i{0}; i <= 10; ++i)
        std::cout << "Dice: " << (rand()%6 + 1) << std::endl;



    return 0;
}
