/*
 * In C++, we can allocate memory in two ways:
 *  - Static allocation.
 *  - Dynamic allocation.
 *
 * In static allocation, a fixed amount of memory is allocated to the variables ar arrays before the
 * execution of the program (during compile-time), and we cannot request more memory while the program
 * runs. In static allocation:
 *  - We must know the size of an array or variable during the compile time.
 *  - Memory is allocated and deallocated to the variables by the compiler.
 *
 * Sometimes we will encounter a situation where we don't know in advance how much memeory is needed to 
 * store the data. Thus, dynamic allocation is needed.
 * In dynamic allocation:
 *  - We can get as much memory as we want during the program executon.
 *  - Memory is allocated and deallocated by the programmer during the run-time.
*/

#include <iostream>

int main(){
    // In this case if we initialize an array with ferew characters than the size of an input sentence,
    // then we may get an error. In the other hand if we initialize an array with more characters than
    // the actual size of an input sentence, then the unused memory is wasted. 
    char sentence[10];
    std::cout << "Please write yoyr sentence: " << std::endl;
    std::cin >> sentence;
    std::cout << sentence << "\n";


    return 0;
}
