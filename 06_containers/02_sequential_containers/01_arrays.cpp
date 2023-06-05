/*
 * std::array is a homogeneous container of fixed length. It requires the header <array>. An instance of
 * std::array combines the memory and runtime characteristics of a C array with the interface of an
 * std::vector. In particular, an std::array knows its size. We can use STL algorithms on instances of
 * std::array.
 * Keep a few special rules in mind for initializing an std::array
 *  - std::array<int, 10> arr: The 10 elements are not initialized.
 *  - std::array<int, 10> arr{}: The 10 elements initialized to 0 by default.
 *  - std::array<int, 10> arr{1, 2, 3, 4, 5}: The unspecified elements are initialized to 0 by default.
 * std::array supports three types of index access:
 *  - arr[n];
 *  - arr.at(n);
 *  - std::get<n>(arr);
 * The most commonly used first type of index access using square brackets does not check the boundaries of 
 * the arr. This is in contrast to arr.at(n). We will eventually get an std::range-error exception. The last
 * form is the above list shows the relationship of std::array with the std::tuple, becuase both are 
 * containers of fixed length.
 *  Criteria                                Array
 *  Size                                    static
 *  Implementation                          static array
 *  Access                                  random
 *  Optimized for insert and delete at      ------
 *  Memory reservation                      ------
 *  Release Memory                          ------
 *  Strength                                no memory allocation; minimal memory requirements
 *  Weakness                                no dynamic memory; memory allocation
*/
#include <iostream>
#include <array>
#include <numeric>

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a){
    for(const auto& e : a)
        out << e << " ";
    return out;
}

int main(){
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "arr contains: " << arr << std::endl;
    
    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    std::cout << "Sum: " << sum << std::endl; // 55
    
    double mean = sum / arr.size(); // 5.5
    std::cout << "mean: " << mean << std::endl;
    
    // Check if arr[0] is the same as std::get<0>(arr)
    std::cout << std::boolalpha;
    std::cout << "arr[0] == std::get<0>(arr)): " << (arr[0] == std::get<0>(arr)) << std::endl; // true


    return 0;
}
