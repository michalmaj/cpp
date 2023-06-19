/*
 * The numeric library is host to several numeric functions.
 * The numeric algorithms std::accumulate, std::adjacent_difference, std::partial_sum, std::inner_product
 * and std::iota and the six additional C++17 algorithms std::exclusive_scan, std::inclusive_scan,
 * std::transform_inclusive_scan, std::reduce, and std::transform_reduce are special. All of them are 
 * defined in the header <numeric>. They are widely applicable, because they can be configured with a
 * callable.
*/
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a){
    for(const auto& e : a)
        out << e << " ";
    return out;
}

int main(){
    std::array<int, 9> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "arr contins: " << arr << std::endl;
    
    std::cout << "std::accumulate(arr.begin(), arr.end(), 0): " << 
        std::accumulate(arr.begin(), arr.end(), 0) << std::endl;
    
    // Own multiplies
    std::cout << "std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){return a * b;}): " << 
        std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){return a * b;}) << std::endl;
        
    // Built-in multiplies
    std::cout << "std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<>(): " << 
        std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<>()) << std::endl;
        
    std::cout << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> myVec;
    
    std::cout << "adjacent_difference:\n";
    std::adjacent_difference(vec.begin(), vec.end(), std::back_inserter(myVec), [](int a, int b){
    return a * b;});
    std::cout << "vec: " << vec << std::endl;
    std::cout << "myVec: " << myVec << std::endl;
    
    std::cout << std::endl;
        

     // (v1 * a1) + (v2 * a2) + (v3 * a3) + ... + (vn * an)
    std::cout << "std::inner_product(vec.begin(), vec.end(), arr.begin(), 0): " <<
    std::inner_product(vec.begin(), vec.end(), arr.begin(), 0) << std::endl;
    
    std::cout << std::endl;
    
    myVec = {};
    std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
    std::cout << "partial_sum: " << myVec << std::endl; 

    std::cout << std::endl;
    
    std::vector<int> myLongVec(100);
    std::iota(myLongVec.begin(), myLongVec.end(), 2000);
    std::cout << "iota: " << myLongVec << std::endl;
       


    return 0;
}
