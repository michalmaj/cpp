/*
 * We can sort a range with std::sort or std::stable_sort or sort until a position with std::partial_sort.
 * In addition std::partial_sort_copy copies the partially sorted range. With std::nth_element we can assign 
 * an element the sorted position in the range. We can check with std::is_sorted if a range is sorted. If
 * we want to know until position a range is sorted, use std::is_sorted_until.
 * Per default the predefined function object std::less is used as a sorting criterion. However, we can use
 * our sorting criterion. This has obey the strict weak ordering.
*/
#include <algorithm>
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
    std::cout << std::boolalpha << std::endl;
    
    std::string str{"RUdAjdDkaACsdfjwldXmnEiVSEZTiepfgOIkue"};
    std::cout << "str contains: " << str << std::endl;
    std::cout << "str.size(): " << str.size() << std::endl;
    std::cout << "std::is_sorted(str.begin(), str.end()): " << 
                  std::is_sorted(str.begin(), str.end()) << "\n";
                  
    std::cout << std::endl;
    
    std::partial_sort(str.begin(), str.begin()+30, str.end());
    std::cout << str << std::endl;
    
    auto sortUntil = std::is_sorted_until(str.begin(), str.end());
    std::cout << "Sorted until: " << *sortUntil << std::endl;
    for(auto it = str.begin(); it != sortUntil; ++it)
        std::cout << *it;
    std::cout << std::endl << std::endl;
    
    std::vector<int> vec{1, 0, 4, 3, 5};
    std::cout << vec << std::endl;
    auto vecIt = vec.begin();
    while(vecIt != vec.end()){
        std::nth_element(vec.begin(), vecIt++, vec.end());
        std::cout << std::distance(vec.begin(), vecIt) << "-th ";
        std::cout << vec << std::endl;
    }

    return 0;
}
