/*
 * The unordered associative containers store their indices in buckets. In which bucket the index goes
 * depends on the has function, which maps the key to the index. If different keys are mapped to the same 
 * indes, it;s called a collision. The hash function tries to avoid this.
 * Indices are typically stored in the bucket as a linked list. Since the access to the bucket is constant, 
 * the access to the linked list in the bucket in linear. The number of buckets is called capacity, the
 * average number of elements for each bucket is called the load factor. In general, the C++ runtime 
 * generatesnew buckets if the load factor is greater than 1. This process is called rehashng and can be
 * triggered explicitly.
*/
#include <iostream>
#include <unordered_set>
#include <random>
#include <array>

void getInfo(const std::unordered_set<int>& hash){
    std::cout << "hash.bucket_count(): " << hash.bucket_count() << std::endl;
    std::cout << "hash.load_factor(): " << hash.load_factor() << std::endl;
}

int main(){
    std::array<int, 100> arr{0};
    std::random_device r;
    std::default_random_engine e(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    for(size_t i = 0; i < arr.size(); ++i)
        arr.at(i) = uniform_dist(e);
    
    std::unordered_set<int> hash(arr.begin(), arr.end());
    
    // With the method max_load_factor, we can read and set the load factor in order to influence the 
    // probablity of collisions and rehasing. We want to emphasize one point in the this example: the key
    // 500 is in the some n bucket at first, but after rehashing, it is in the 500th bucket.
    std::cout << "hash.max_load_factor(): " << hash.max_load_factor() << std::endl;
    
    std::cout << std::endl;
    getInfo(hash);
    std::cout << std::endl;
    
    hash.insert(500);
    std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl;

    std::cout << std::endl;
    getInfo(hash);
    std::cout << std::endl;
    
    hash.rehash(500);
    std::cout << "hash.bucket(500): " << hash.bucket(500) << std::endl;
    
    std::cout << std::endl;
    getInfo(hash);
    std::cout << std::endl;

    return 0;
}
