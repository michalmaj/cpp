/*
 * We can determine the mnimum, the maximum, and minimum and maximum pair of a range with the algorithms
 * std::min_element, std::max_element and std::minmax_element. Each algorithm can be configured with a 
 * binary predicate.
 * If a range has more than one minimum or maximum element, the first one is returned.
*/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

// We can use it instead of lambda inside std::transform
std::string toString(int i){
    std::stringstream buff;
    buff.str("");
    buff << i;
    std::string val = buff.str();
    return val; 
}

int toInt(const std::string& s){
    std::stringstream buff;
    buff.str("");
    buff << s;
    int value;
    buff >> value;
    return value; 
}

int main(){
    std::vector<int> myInts;
    std::vector<std::string> myStrings{
        "94", "5", "39", "-4", "-49", "1001", "-77", "23", "0", "84", "59", "96", "6", "-94", "87"
    };
    std::transform(myStrings.begin(), myStrings.end(), std::back_inserter(myInts), [](std::string s){
    return std::stoi(s);});
    std::cout << "myInts: " << myInts << std::endl;
    std::cout << std::endl;
    
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::string> myStrs;
    std::transform(vec.begin(), vec.end(), std::back_inserter(myStrs), [](int i){
    return std::to_string(i);});
    std::cout << "myStrs: " << myStrs << std::endl;
    std::cout << std::endl;
    
    auto paInt = std::minmax_element(myInts.begin(), myInts.end());
    std::cout << "std::minmax_element(mynts.begin(), myInts.end()): " << "(" << *paInt.first << ", " <<
    *paInt.second << ")" << std::endl;
    
    auto paStr = std::minmax_element(myStrings.begin(), myStrings.end());
    std::cout << "std::minmax_elements(myStrings.begin(), myStrings.end());: " << "(" << *paStr.first <<
    ", " << *paStr.second << ")" << std::endl;
    
    auto paStrAsInt = std::minmax_element(myStrings.begin(), myStrings.end(), []
    (const std::string& a, const std::string& b){return std::stoi(a) < std::stoi(b);});
    std::cout << "std::minmax_elements(myStrings.begin(), myStrings.end());: " << "(" << *paStrAsInt.first 
    << ", " << *paStrAsInt.second << ")" << std::endl;


    return 0;
}
