/*
 * std::list is a doubled linked list. std::list needs header <list>
 * Although it has similar interface to std::vector or std::deque, std::list is quite different from both of
 * them. That's due to its structure.
 * std::list makes the following points unique:
 *  - It suports no random access.
 *  - Accessing an arbtrary element is slow because we might have to iterate through whe whole list.
 *  - Adding or removing an element is fast, if the iterator points to right place.
 *  - If we add or remove an element, the iterator remains valid.
 * Because of its special structure, std:list has a few special methods:
 *  Method                  Description
 *  lis.merge(c)            Merge the sorted list c into sortd list lis, so that lis remains sorted.
 *  lis.merge(c, op)        Merge the sorted list c into sorted list lis, so that lis remains sorted. Use op 
                            as sorting criteria.
 *  lis.remove(val)         Remove all elements from lis with value val.
 *  lis.remove_if(pre)      Remove all elements from lis, fulfilling the predicate pre.
 *  lis.unique()            Remove adjacent element with the same value.
 *  lis.unique(pre)         Remove adjecent elements, fulfilling the predicate pre.
 *
 *  Criteria                                List
 *  Size                                    dynamic
 *  Implementation                          doubled linked list
 *  Access                                  forward and backward
 *  Optimized for insert and delete at      begin and end: O(1), arbitrary: O(1)
 *  Memory reservation                      no
 *  Release Memory                          always
 *  Strength                                insertion and deletion at arbitrary position
 *  Weakness                                no random access
*/
#include <iostream>
#include <list>
#include <algorithm>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& l){
    for(const auto& e : l)
        out << e << " ";
    return out;
}


int main(){
    std::list<int> l1{15, 2, 18, 19, 4, 15, 1, 3, 18, 5, 
                      4, 7, 17, 9, 16, 8, 6, 6, 17, 1, 2};
    l1.sort();
    std::cout << "l1 contains: " << l1 << std::endl;
    
    l1.unique();
    std::cout << "l1 contains: " << l1 << std::endl;
    
    std::list<int> l2{10, 11, 12, 13, 14};
    
    // Insert before given element (in this case find 15 and put l2 before)
    l1.splice(std::find(l1.begin(), l1.end(), 15), l2);
    std::cout << "l1 contains: " << l1 << std::endl;

    return 0;
}
