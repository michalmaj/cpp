/*
 * We have with std::replace, std::replace_if, std::replace_copy, and std::replace_copy_if four variations
 * to replace elements in a range. The algorithms differ in two aspects. First, does does the algorithm need
 * a predicate? Second, does the algorithm copy the elements in the destination range?
 *  std::replace - replaces the old elements in the range with newVAlue, if the old element has the value  
 *                 old.
 *  std::replace_if - replaces the old elements of the range with newValue, if the old element fulfils the
 *                    predicate pred.
 *  std::replace_copy - replaces the old elements in the range with newValue, if the old element has the
 *                      value old.
 *  std::replace_copy_if - replaces the old elements of the range with newValue, ih the old value fulfils 
 *                         the predicate pred.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main(){
    std::string str{"Only for testing purpose."};
    std::cout << "str contains: " << str << std::endl;
    
    std::replace(str.begin(), str.end(), ' ', '1'); // Replace spaces wth '1'
    std::cout << "str contains: " << str << std::endl;
    
    std::replace_if(str.begin(), str.end(), [](char c){return c== '1';}, '2'); // Replace '1' with '2'
    std::cout << "str contains: " << str << std::endl;
  
    
    std::string str2;
    std::replace_copy(str.begin(), str.end(), std::back_inserter(str2), '2', '3');
    std::cout << "str2 contains: " << str2 << std::endl;
    
    std::string str3;
    std::replace_copy_if(str2.begin(), str2.end(), std::back_inserter(str3), [](char c){
        return c == '3';
    }, '4');
    std::cout << "str3 contains: " << str3 << std::endl;


    return 0;
}
