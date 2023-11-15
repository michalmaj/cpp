// Non-Type Template Parameter
#include <array>
#include <iostream>
#include <algorithm>

int main(){
    std::cout << std::endl;

    // Output the array
    std::array<int, 8> array1{1, 2, 3, 4, 5, 6, 7, 8};
    std::for_each(array1.begin(), array1.end(), [](int v){std::cout << v << " ";});

    std::cout << std::endl;

    // Calculate the sum of the array by using a global variable
    int sum{0};
    std::for_each(array1.begin(), array1.end(), [&sum](int v){sum+=v;});
    std::cout << "Sum of array: " << sum << std::endl;

    // Change each array element to the second power
    std::for_each(array1.begin(), array1.end(), [](int& v){v*=v;});
    std::for_each(array1.begin(), array1.end(), [](int v){std::cout << v << " ";});
    std::cout << std::endl;

    return 0;
}