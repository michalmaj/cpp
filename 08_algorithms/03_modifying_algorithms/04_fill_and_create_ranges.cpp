/*
 * We can fill a range with std::fill and std::fill_n. We can generate new elements with std::generate and
 * std::generate_n.
 *  std::fill - fills a range with elements.
 *  std::fill_n - fills a range with n new elements.
 *  std::generate - generates a range with a generator gen.
 *  std::generate_n - generates n elements of a range with the generator gen.
 *
 * The algorithms expect the value val or a generator gen as an argument. gen has to be a function taking no
 * return argument and returning the new value. The return value of the algorithm std::fill_n and 
 * std::generate_n is an output iterator, pointing to the last created element.
*/
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

int getNext(){
    static int next{};
    return ++next;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> vec(20);
    std::fill(vec.begin(), vec.end(), 2023);
    std::cout << "vec contains: " << vec << std::endl;

    std::cout << std::endl;
    
    std::generate_n(vec.begin(), 15, getNext);
    std::cout << "vec contains: " << vec << std::endl;

    return 0;
}


