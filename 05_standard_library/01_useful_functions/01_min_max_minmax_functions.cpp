/*
 * This family of functions allows us to find the minimum and maximum is a set of data.
 * The many variations of the min, max, and minmax functions apply to values and initializer lists. These
 * functions need the header <algorithm>. Nearly the same holds for the functions std::move, std::forward,
 * and std::swap. You can apply them to arbitrary values. These three functions are defined in the header
 * <utility>.
 *
 * The functions std::min, std::max, std:minmax defined in the header <algorithm>, act on values and
 * initializer lists and give you the requested value back as result. In the case os std::minmax, we get
 * an std::pair. The first element of the pair is the minimum, the second is the maximu of the values. By
 * default, the lesss operator< is used, but you can specify your comparison operator. This function needs
 * two arguments and returns a boolean. Functions thet either return true or false are called predicates.
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::cout << "std::min(2011, 2014): " << std::min(2011, 2014) << std::endl;
    std::cout << "std::min({{3, 1, 2011, 2014, -5}): " << std::min({3, 1, 2011, 2014, -5}) << "\n";
    
    std::cout << "std::min(-10, -5), wth own predicate (both values are abs): " <<
    std::min(-10, -5, [](int a, int b){return std::abs(a) < std::abs(b);}) << std::endl;
    
    std::pair<int, int> pairInt = std::minmax(2011, 2014);
    auto pairSeq = std::minmax({3, 1, 2011, 2014, -5});
    auto pairAbs = std::minmax(-10, -5, [](int a, int b){return std::abs(a) < std::abs(b);});
    
    std::cout << "std::minmax(2011, 2014): " << pairInt.first << ", " << pairInt.second << "\n";
    std::cout << "std::minmax({3, 1, 2011, 2014, -5}): " << pairSeq.first << ", " << pairSeq.second << "\n";
    std::cout << "std::minmax(-10, -5, [](int a, int b){return std::abs(a) < std::abs(b);}): " <<
    pairAbs.first << ", " << pairAbs.second << "\n";
    
    // Structured binding
    auto [first, second] = std::minmax(1, -9);
    std::cout << "std::minmax(1, -9): " << first << ", " << second << "\n";
    

    return 0;
}
