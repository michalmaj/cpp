/*
 * For a container cont, use cont.empty() to see if the container is empty. cont.size() returs the current
 * number of elements, and cont.max_size() returns the maximum number of elements cont can have. The 
 * maximum number of elements is implementation defined.
 *
 * Use cont.empty() instead of cont.size()
 * For a container cont, use the method cont.empty() instead of (cont.size() == 0) to determine if the 
 * container is empty. First, cont.empty() is, in general, faster than (cont.size() == 0); second, the
 * contaner std::forward_list has no method size().
*/
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main(){
    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::map<std::string, int> str2Int = {
        {"bart", 12345},
        {"jenne", 34929},
        {"huber", 840284}
    };
    std::set<double> douSet{3.14, 2.5};
    
    std::cout << std::boolalpha;
    std::cout << intVec.empty() << std::endl; // false
    std::cout << str2Int.empty() << std::endl; // false
    std::cout << douSet.empty() << std::endl; // false
    
    std::cout << intVec.size() << std::endl; // 9
    std::cout << str2Int.size() << std::endl; // 3
    std::cout << douSet.size() << std::endl; // 2
    
    std::cout << intVec.max_size() << std::endl;    // 2305843009213693951
    std::cout << str2Int.max_size() << std::endl;   // 128102389400760775
    std::cout << douSet.max_size() << std::endl;    // 230584300921369395


    return 0;
}
