/*
 * A simple performance test should give an idea of the overall performance.
*/
#include <chrono>
#include <iostream>
#include <memory>
#include <ios>

static const long long numInt = 100'000'000;


int main(){
    auto start = std::chrono::system_clock::now();
    
    for(auto i{0}; i < numInt; ++i){
        //int* tmp(new int(i));
        //delete tmp;
        
        //std::shared_ptr<int> tmp(new int(i));
        
        //std::shared_ptr<int> tmp(std::make_shared<int>(i));
        
        std::unique_ptr<int> tmp(new int(i));
        
        //std::unique_ptr<int> tmp(std::make_unique<int>(i));
    }
    
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "time native: " << dur.count() << " seconds\n";

    return 0;
}
