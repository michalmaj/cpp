/*
 * Scan operation are useful when working with prefix sums.
 *
 * exclusive_scan: computes the exclusive prefix sum using a binary operation. Behaves similar to 
 * std::reduce, but provides a range of all prefix sums. Excludes the last element in each iteration.
 *
 * inclusive_scan: computes the inclusive prefix sum using a binary operation. Behaves similar to 
 * std::reduce, but provides a range of all prefix sums. Includes the last element in each iteration.
 *
 * transform_exclusive_scan: first transform each element and them computes the exclusive prefix sums.
 *
 * transform_inclusive_scan: first transforms each element of the input range and then computes the 
 * inclusive prefix sum.
*/
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <execution>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    // for_each_n
    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::for_each_n(std::execution::par, intVec.begin(), 5,
                    [](int& arg){arg *= arg;});
    std::cout << "for_each_n: " << intVec << std::endl;
    
    // exclusive_scan and inclusive_scan
    std::vector<int> resVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
//    std::exclusive_scan(std::execution::par, // g++ doesn'twork with 12.1, msvc works fine!
//                        resVec.begin(), resVec.end(), resVec.begin(), 1,
//                        [](int first, int second){return first * second;});
//    std::cout << "exclusive_scan: " << resVec << std::endl;
    
    std::vector<int> resInt; // We need second vector (g++ can't do it in place)
    std::exclusive_scan(std::execution::par,
                    resVec.begin(), resVec.end(), std::back_inserter(resInt), 1,
                    [](int first, int second){return first * second;});
    std::cout << "exclusive_scan: " << resInt << std::endl;

    std::vector<int> resVec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::inclusive_scan(std::execution::par,
                        resVec2.begin(), resVec2.end(), resVec2.begin(),
                        [](int first, int second){return first * second;}, 1);
    std::cout << "inclusive_scan: " << resVec2 << std::endl;
    
    std::cout << std::endl;
    
    // transform_exclusive_scan and trnasform_inclusive_scan
    std::vector<int> resVec3{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> resVec4(resVec3.size());             
    std::transform_exclusive_scan(std::execution::par,
                                  resVec3.begin(), resVec3.end(),
                                  resVec4.begin(), 0,
                                  [](int first, int second){return first + second;},
                                  [](int arg){return arg *= arg;});
    std::cout << "transform_exclusive_scan: " << resVec4 << std::endl;
    
    std::vector<std::string> strVec{"Only", "for", "testing", "purpose"};             
    std::vector<int> resVec5(strVec.size());
    std::transform_inclusive_scan(std::execution::par,         
                                  strVec.begin(), strVec.end(), 
                                  resVec5.begin(),
                                  [](auto fir, auto sec){ return fir + sec; },
                                  [](auto s){ return s.length(); }, 0);
    std::cout << "transform_inclusive_scan: " << resVec5 << std::endl;
    
    std::cout << std::endl;
    
    // reduce and transform_reduce
    std::vector<std::string> strVec2{"Only", "for", "testing", "purpose"};
    
    std::string res = std::reduce(std::execution::par,
                                  strVec2.begin() + 1, strVec2.end(), strVec2.at(0),
                                  [](const auto& f, const auto& s){return f + ":" + s;});
    std::cout << "reduce: " << res << std::endl;
    
    size_t res7 = std::transform_reduce(std::execution::par,
                                        strVec2.begin(), strVec2.end(), 0,
                                        [](size_t a, size_t b){return a + b;},
                                        [](const std::string& s){return s.length();});
                                        
    std::cout << "transform_reduce: " << res7 << std::endl;
    

    return 0;
}
