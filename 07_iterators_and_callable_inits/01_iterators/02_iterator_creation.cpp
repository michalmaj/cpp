/*
 * Categories: iterators can be categorized into three primary types, each with its own adventages.
 * Their capabilities can categorize iterator. C++ has forward, bidirectional and random access iterators.
 * With the forward iterator, we can iterate the contaner forward, with the bidirectional iterator, in both
 * directions. With the random access iterator, we can directly access an arbitrary element. In particular,
 * this means for the last one, that we can use iterator arithmetic and ordering comparisons (e.g.: <). The
 * category of an iterator depends on the type of container used.
 * In the table below is a representation of containers and their iterator categories. The bidirectional
 * iterator includes the forward iterator functionalities, and the random access iterator includes the
 * forward and the bidirectonal iterator functionalities. It and It2 are iteratorsm n is a natural number.
 *  Iterator category               Properties                          Container
 *  --------------------------------------------------------------------------------------------------------
 *  Forward iterator                ++It, It++, *It                     unordered associative container
 *                                  It == It2, It != It2                std::forward_list
 *  --------------------------------------------------------------------------------------------------------
 *  Bidirectional iterator          --It, It--                          ordered associative container
 *                                                                      std::list
 *  --------------------------------------------------------------------------------------------------------
 *  Random access iterator          It[i]                               std::array
 *                                  It += n, It -= n                    std::vector
 *                                  It + n, It - n                      std::deque
 *                                  n + It                              std::string
 *                                  It - It2
 *                                  It < It2, It <= It2, It > It2
 *                                  It >= It2
 *  --------------------------------------------------------------------------------------------------------
 * 
 * Iterator Creation
 * Each container generates its suitable iterator on request. For example, as std::unordered_map generates
 * constant and non-constant forward iterators:
 *  std::unordered_map<std::string, int>::iterator unMapIt= unordMap.begin();
 *  std::unordered_map<std::string, int>::iterator unMapIt= unordMap.end();
 *  std::unordered_map<std::string, int>::const_iterator unMapIt= unordMap.cbegin();
 *  std::unordered_map<std::string, int>::const_iterator unMapIt= unordMap.cend(); 
 * In addition, std::map supports the backward iterators:
 *  std::map<std::string, int>::reverse_iterator mapIt= map.rbegin();
 *  std::map<std::string, int>::reverse_iterator mapIt= map.rend();
 *  std::map<std::string, int>::const_reverse_iterator mapIt= map.rcbegin();
 *  std::map<std::string, int>::const_reverse_iterator mapIt= map.rcend();
 * Note:
 * Use auto for iterator defnition.
 * Iterator definition is very labour intensive. The automatic type deduction auto reduces the writing to 
 * the bare minimum.
 *  std::map<std::string, int>::const_reverse_iterator
 *  mapIt= map.rcbegin();
 *  auto mapIt2= map.rcbegin();
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


int main(){
    std::cout << std::endl;

    std::unordered_map<std::string, int> unordMap{
        {"Rainer", 1966}, {"Beatrix", 1966}, {"Juliette", 1997}, {"Marius", 1999}
    };
    
    std::unordered_map<std::string, int>::const_iterator endMapIt = unordMap.end();
    std::unordered_map<std::string, int>::iterator mapIt;
    
    for(mapIt = unordMap.begin(); mapIt != endMapIt; ++mapIt)
        std::cout << "{" << mapIt->first <<  ", " << mapIt->second << "} ";
    std::cout << std::endl << std::endl;
    
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    std::vector<int>::const_iterator vecEndIt = myVec.end();
    std::vector<int>::iterator vecIt;
    
    for(vecIt = myVec.begin(); vecIt != vecEndIt; ++vecIt)
        std::cout << *vecIt << " ";
    std::cout << std::endl << std::endl;
    
    std::vector<int>::const_reverse_iterator vecEndRevIt = myVec.rend();
    std::vector<int>::reverse_iterator vecRevIt;
    for(vecRevIt = myVec.rbegin(); vecRevIt != vecEndRevIt; ++vecRevIt)
        std::cout << *vecRevIt << " ";
    std::cout << std::endl << std::endl;

    return 0;
}
