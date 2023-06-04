/*
 * We can construct each container using a multitude of constructors. To delete all elements of container
 * cont use cont.clear(). It makes no difference if we create and delete a container or if we add and remove
 * elements. Each time the container takes care of memory management.
 * The table below shows the constructors and destructos of a container. All these functions can be used 
 * with std::vector:
 *  Type:                           Example
 *  Default                         std::vector<int> vec1
 *  Range                           std::vector<int> vec2(vec1.begin(), vec1.end())
 *  Copy                            std::vector<int> vec3(vec2)
 *  Copy                            std::vector<int> vec3 = vec2;
 *  Move                            std::vector<int> vec4(std::move(vec3))
 *  Move                            std::vector<int> vec4 = std::move(vec3)
 *  Sequence (initializer list)     std::vector<int> vec5{1, 2, 3, 4, 5}
 *  Sequence (initializer list)     std::vector<int> vec5 = {1, 2, 3, 4, 5}     
 *  Destructor                      vec5.~vector()
 *  Delete elements                 vec5.clear() 
 *
 * Creation and deletion of a container
 * Because std::array is generated at compile-time, there are a few things that are special. std::array has 
 * no move consructor and can't be created with a range or with an initializer list. However, an std::array
 * can be initialized with an aggregate initialization. Also, std::array has no method for removing its
 * elements.
 */
 #include <iostream>
 #include <map>
 #include <unordered_map>
 #include <vector>
 
 int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::map<std::string, int> m{{"bart", 12345}, {"jenne", 34929}, {"huber", 850284}};
    std::unordered_map<std::string, int> um{m.begin(), m.end()};
    
    for(auto& v : vec)
        std::cout << v << " ";
    std::cout << std::endl << std::endl;
    
    for(auto& e : m)
        std::cout << e.first << " " << e.second << std::endl;
    std::cout << std::endl;
    
    for(auto& [k, v] : um)
        std::cout << k << " " << v << std::endl;
    std::cout << std::endl;
 
    std::vector<int> vec2 = vec;
    std::cout << vec.size() << std::endl;
    std::cout << vec2.size() << std::endl;
    
    std::cout << std::endl;
    
    std::vector<int> vec3 = std::move(vec);
    std::cout << vec.size() << std::endl;
    std::cout << vec3.size() << std::endl;
    
    
 
    return 0;
 }
