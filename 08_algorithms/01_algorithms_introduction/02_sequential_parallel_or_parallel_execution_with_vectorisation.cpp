/*
 * By using an execution policy in C++17, we can specify whether the algorithm should run sequentially, in
 * parallel, or in parallel with vectorization.
 *
 * Execution Policies
 * The policy tag specifies whether an algorithm should run sequentially, in parallel, or in parallel with
 * vectorization.
 *  - std::execution::seq - runs the algorithm sequentially.
 *  - std::execution::par - runs the algorithm is parallel on multiple threads.
 *  - std::execution::par_unseq - runs the algorithm in parallel on multiple threads and allows the 
 *                                interleaving of individual loops; permits a vectorised version with SIMD
 *                                (Single Instruction Multiple Data) extensions.
*/
// In linux terminal check: time ./a.out
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    
    // Commnet all below except one to check time
    
    // 1. Standard sequential sort
//    std::sort(v.begin(), v.end());
    
    // 2. Sequential execution
//    std::sort(std::execution::seq, v.begin(), v.end());
    
    // 3. Permitting parallel execution
//    std::sort(std::execution::par, v.begin(), v.end());

    // 4. Permitting parallel and vectorised execution
    std::sort(std::execution::par_unseq, v.begin(), v.end());


    return 0;
}
