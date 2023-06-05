/*
 * Vectors are more refined version of arrays. They simplify the insertion and deletion of values.
 * std::vector is a homogeneous container, for which it's length can be adjusted at runetime. std::vector
 * needs the header <vector>. As it stores its elements contiguously in memory, std::vector supports pointer
 * arithmetic:
 *  for(int i{0}; i < vec.size(); ++i)
 *      std::cout << (vec[i] == *(vec + i)) << std::endl; // true
 *
 *  Criteria                                Vector
 *  Size                                    dynamic
 *  Implementation                          dynamic array
 *  Access                                  random
 *  Optimized for insert and delete at      end: O(1)
 *  Memory reservation                      yes
 *  Release Memory                          shrink_to_fit
 *  Strength                                95% solution
 *  Weakness                                Insertion and deletion at an arbitrary position: O(n)
 *
 * Note: make sure to distinguish the round and curly braces in the creation of an std::vector. If we 
 * constrct a std::vector, we must keep a few thngs in mind. The constructor with round braces in the
 * following example creates an std::vector with a capacity of 10 elements, while the constructor with curly
 * braces creates as std::vector with the element 10:
 *  std::vector<int> vec(10);
 *  std::vector<int> vec{10};
 * The same rules hold true for the expression std::vector<int>(10, 2023) or std::vector<int>{10, 2023}. In
 * the first case, we get an std::vector with 10 elements, initialised to 2023. In the second case, we get
 * an std::vector with the elements 10 and 2023. The reason for this behaviour is that curly braces are
 * interpreted as initializer list so the sequence constructor is used.
*/
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> vec1; // Empty vector
    std::cout << "vec1: " << vec1 << std::endl;
    
    std::vector<int> vec2(4, 2023); // 4 elements, initialized to 2023
    std::cout << "vec2: " << vec2 << std::endl;
    
    std::vector<int> vec3(vec2.begin(), vec2.end()); // Initialize vector with elelemnts from vec2
    std::cout << "vec3: " << vec3 << std::endl;
    
    std::vector<int> vec4(vec2); // Initialize vector with elements from vec2
    std::cout << "vec4: " << vec4 << std::endl;
    
    std::vector<int> vec5{std::move(vec2)}; // Move elements from vec2, since now vec2 is empty
    std::cout << "vec5: " << vec5 << std::endl;
    
    std::vector<int> vec6{1, 2, 3, 4, 5}; // Vector initialized with initializer list
    std::cout << "vec6: " << vec6 << std::endl;
    
    std::vector<int> vec7(5); // Reserve vector with 5 elements, all initialized to 0
    std::cout << "vec7: " << vec7 << std::endl;
    

    return 0;
}
