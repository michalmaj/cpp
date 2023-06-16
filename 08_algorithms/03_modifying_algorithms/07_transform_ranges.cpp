/*
 * The std::transform algorithm applies a unary or binary callable to a range and copies the modified 
 * elements to the destination range.
 * The difference betwen the two versions is that the first verson applies the callable to each element of 
 * the range; the second version applies the callable to pairs of both ranges in parallel. The returned 
 * iterator points to one position after the last transformed elemnt.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::cout << std::endl;

    std::string str{"abcdefghijklmnopqrstuvwxyz"};
    std::cout << str << std::endl;
    
    std::transform(str.begin(), str.end(), str.begin(), [](char c) {return std::toupper(c);});
    std::cout << str << std::endl;

    std::cout << std::endl;
    
    std::vector<std::string> vecStr{"Only", "for", "testing", "purpose", "."};
    std::vector<std::string> vecStr2(5, "-");
    std::cout << "vecStr contains: " << vecStr << std::endl;
    std::cout << "vecStr2 contains: " << vecStr2 << std::endl;
    
    
    std::vector<std::string> vecRes;
    
    std::transform(vecStr.begin(), vecStr.end(),
                   vecStr2.begin(), std::back_inserter(vecRes),
                   [](const std::string& a, const std::string& b){return std::string(b) + a + b;});
    
    for(const auto& e : vecRes)
        std::cout << e << std::endl;

    return 0;
}
