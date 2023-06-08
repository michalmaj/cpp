/*
 * Performance. That's the simple reason why the unordered associative containers were so long missed in 
 * C++. In the example below, one million randomly created values are read from an std::map and
 * std:unordered_map with 10 million values. The impresive resut is that the linear access time of an
 * unordered associative container in 20 times faster than the access time of an ordered associative 
 * container. That is just the difference between constant and logarithmic complexity O(logn) of these
 * operations.
*/
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <unordered_map>

int main(){
    const long long mapSize = 10'000'000;
    const long long accSize = 1'000'000;
    
    std::map<int, int> myMap;
    std::unordered_map<int, int> myHash;
    
    for(long long i = 0; i < mapSize; ++i){
        myMap[i] = i;
        myHash[i] = i;
    }
    
    std::vector<int> randValues;
    randValues.reserve(accSize);
    
    // Rando values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDsit(0, mapSize);
    for(long long i = 0; i < accSize; ++i)
        randValues.push_back(uniformDsit(engine));
        
    auto start = std::chrono::system_clock::now();
    for(long long i = 0; i < accSize; ++i)
        myMap[randValues[i]];
    
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Time for std::map: " << dur.count() << " seconds\n";
    
    auto start2 = std::chrono::system_clock::now();
    for(long long i = 0; i < accSize; ++i)
        myHash[randValues[i]];
    
    std::chrono::duration<double> dur2 = std::chrono::system_clock::now() - start2;
    std::cout << "Time for std::unordered_map: " << dur2.count() << " seconds\n";

    return 0;
}
