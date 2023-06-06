/*
 * std::forward_list is a singly linked list, which needs the header <forward_list>. std::forward_list has a
 * drastically reduced interface and is optimized for minimal memory requirements.
 * std::forward_list has a lot in common with std::list:
 *  - It doesn't support the random access.
 *  - The access of an arbitrary element is slow because in the worst case, we have to iterate forward 
 *    through the whole list.
 *  - To add or remove an elemnt is fast, if the iterator points to the right place.
 *  - If we add or remove an element, the iterator points to the right place.
 *  - Operations always refere to the beginning of the std::forward_lsit ot the position past the current
 *    element.
 *
 * Being able to terate through an std::forward_list forward as a great impact. The terator cannot be
 * decremented and therefore has no backward iterator. std::forward_list is the only sequential container
 * which doesn't know its size.
 *
 * std::forward_list has a very special domain:
 * std::forward_list is the replacement for single linked lists. It's optimized for minimal memory
 * management and performance if the insertion, extraction, or movement of elements only affects adjacent
 * elements. This is typical for sorting algorithms.
 *
 * The following are the special methods of std::forward_list
 *  Method                                  Description
 *  forw.before_begin()                     Returns an iterator before the first element.
 *  forw.emplace_after(pos, args...)        Creates an element after pos with the arguments args... .
 *  forw.emplace_front(args...)             Creates an element at the beginning of forw with the arguments
 *                                          args... .
 *  forw.erase_after(pos, ...)              Removes from forw the element pos or a range of elements,
 *                                          starting with pos.
 *  forw.insert_after(pos, ...)             Inserts new elements after pos. These elements can be single
 *                                          elements, ranges or initializer lists.
 *  forw.merge(c)                           Merges the sorted forward_lis c into sorted forward list forw, 
 *                                          so that forw keeps sorted.
 *  forw.merge(c, op)                       Merges the forward sorted list c into sorted forward list forw,
 *                                          so that forw keeps sorted. Uses op as sorting criteria.
 *  forw.splice_after(pos, ...)             Splits the elements if forw before pos. The elements can be
 *                                          single elements, ranges or lists.
 *  forw.unique()                           Removes adjacent element with the same value.
 *  forw.unique(pre)                        Removes adjacent elements, fulfilling the predicate pre.
 *
 *  Criteria                                Forward List
 *  Size                                    dynamic
 *  Implementation                          single linked list
 *  Access                                  forward
 *  Optimized for insert and delete at      begin: O(1), arbitrary: O(1)
 *  Memory reservation                      no
 *  Release Memory                          always
 *  Strength                                insertion and deletion; minimal memeory requirements
 *  Weakness                                no random access
*/
#include <iostream>
#include <algorithm>
#include <forward_list>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::forward_list<T>& l){
    for(const auto& e : l)
        out << e << " ";
    return out; 
}

int main(){
    std::cout << std::boolalpha;
    
    std::forward_list<int> forw;
    std::cout << "forw.empty(): " << forw.empty() << std::endl;
    
    forw.push_front(7);
    forw.push_front(6);
    forw.push_front(5);
    forw.push_front(4);
    forw.push_front(3);
    forw.push_front(2);
    forw.push_front(1);
    
    std::cout << "forw contains: " << forw << std::endl;
    
    forw.erase_after(forw.before_begin()); // remove 1st element
    std::cout << "forw.front(): " << forw.front() << std::endl; // 2
    
    std::forward_list<int> fl;
    fl.insert_after(fl.before_begin(), 1);
    fl.insert_after(++fl.before_begin(), 2);
    fl.insert_after(++(++(fl.before_begin())), 3);
    fl.push_front(1000);
    std::cout << "fl contans: " << fl << std::endl;
    
    auto itTo5 = std::find(forw.begin(), forw.end(), 5);
    forw.splice_after(itTo5, std::move(fl));
    std::cout << "forw contains: " << forw << std::endl;
    std::cout << "fl contans: " << fl << std::endl;
    
    forw.sort();
    std::cout << "forw contains: " << forw << std::endl;
    
    forw.reverse();
    std::cout << "forw contains: " << forw << std::endl;
    
    forw.unique();
    std::cout << "forw contains: " << forw << std::endl;
    

    return 0;
}
