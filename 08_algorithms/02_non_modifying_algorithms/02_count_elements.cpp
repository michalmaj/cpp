/*
 * Count algorithms assist us in counting the number of elements in a reange which satisfy a certain 
 * predicate.
 * We can count elements with the STL with and without a predicate.
 * Count algorithms take input iterators as arguments and return the number of elements matching val or the
 * predicate.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main(){
    std::string str{"abcdabAAAaefaBqeaBCQEaadsfdewAAQAaafbd"};
    std::cout << "count letter 'a': " << std::count(str.begin(), str.end(), 'a') << std::endl;
    
    std::cout << "count letter 'a' and 'A': " << std::count_if(str.begin(), str.end(), [](char a)
        {return std::toupper(a) == 'A';}
    ) << std::endl;
    
    std::cout << "count upper case letters: " << std::count_if(str.begin(), str.end(), [](char a)
        {return std::isupper(a);}
    ) << std::endl;
    
    return 0;
}
