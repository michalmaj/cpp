/*
 * Rearrange the values in our range randomly, using std::random_shuffle and std::shuffle.
 * We can randomly shuffle ranges with:
 *  std::random_shuffle - randomly shuffles the elements in a range.
 *  std::shuffle - randomly shuffles the elements in the range, by using the random number generator.
 * The algorithms need random access iterators. RanNumGen&& gen has to be callable, taking an arguent and
 * returning a value within its arguments. URNG&& gen has to be a uniform random number generator.
 * Prefer std::shufle - use std::shuffle instead of std::random_shuffle. std::random_shuffle has been
 * deprecated since C++14 and removed in C++17, because it uses the C function rand() internally.
*/
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> vec1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> vec2(vec1);
    std::cout << "vec1 contains: " << vec1 << std::endl;
    std::cout << "vec2 contains: " << vec2 << std::endl;
    
    std::cout << std::endl;
    
    std::random_shuffle(vec1.begin(), vec1.end());
    std::cout << "shuffled vec1: " << vec1 << std::endl;
    
    std::cout << std::endl;
    
    // Create own seed
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(vec2.begin(), vec2.end(), std::default_random_engine(seed));
    std::cout << "shuffled vec2: " << vec2 << std::endl;

    return 0;
}
