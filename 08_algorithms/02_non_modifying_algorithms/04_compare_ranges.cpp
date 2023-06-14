/*
 * With std::equal we can compare ranges on equality. With std::lexicographical_compare and std::mismatch
 * we discover which range is the smaller one.
 *  std::equal - checks if both ranges are equal.
 *  std::mismatch - finds the first postion at which both ranges are not equal.
 *  lexicographical_compare - checks if the first range is smaller than the second.
 *
 * The algorithm take input iterators and eventually a binary predicate. std::msmatch returns as its result
 * a pair pa of inputs iterators. pa.first holds an input iterator for the first element that is not equal.
 * pa.second hold the corresponding input iterator for the second range. If both ranges are identical, we
 * get two end iterators.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main(){
    std::cout << std::boolalpha << std::endl;
    
    std::string str1{"Only For Testing Purpose."};
    std::string str2{"only for testing purpose."};

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;

    std::cout << std::endl;
    
    std::cout << "std::equal(str1.begin(), str1.end(), str2.begin()): " << 
    std::equal(str1.begin(), str1.end(), str2.begin()) << std::endl;
    
    auto cmp = [](char c1, char c2){return std::toupper(c1) == std::toupper(c2);};
    std::cout << "std::equal(str1.begin(), str1.end(), str2.begin(), cmp: " << 
    std::equal(str1.begin(), str1.end(), str2.begin(), cmp) << std::endl;
    
    std::cout << std::endl;
    
    auto pair = std::mismatch(str1.begin(), str1.end(), str2.begin());
    if(pair.first == str1.end())
        std::cout << "str1 and str2 are equal\n";
    else{
        std::cout << "str1 and str2 are different at position: " << std::distance(str1.begin(), pair.first)
        << " with (" << *pair.first << ", " << *pair.second << ")\n";
    }
    
    // We can reuse our iterator
    pair = std::mismatch(str1.begin(), str1.end(), str2.begin(), cmp);
    if(pair.first == str1.end())
        std::cout << "str1 and str2 are equal\n";
    else{
        std::cout << "str1 and str2 are different at position: " << std::distance(str1.begin(), pair.first)
        << " with (" << *pair.first << ", " << *pair.second << ")\n";
    }
    
    return 0;
}
