/*
 * What is a heap?
 * A heap is a binary search tree in which parent elements are always bigger than its child elements. Heap
 * trees are optimized for the efficient sorting of elements.
 *
 * We can create with std::make_heap a heap. We can psuh with std::push_heap new elementson the heap. On the
 * contrary, we can pop the largest element with std::pop_heap from the heap. Both operations respect the
 * heap characteristics. std::push_heap moves the last element of the range on the heap; std::pop_heap moves
 * the biggest element of the heap to the last position in the range. We can check with std::is_heap if a
 * range is a heap. We can determine with std::is_heap_until until which position the range is heap.
 * std::sort_heap sorts the heap.
 * With std::pop_heap we can remove the biggest element from the heap. Afterwards, the biggest element is 
 * the last element of the range. To remove t from the heap h, use h.pop_back.
 *
 * The heap algorthms require that the ranges and the algorthms use the same sorting criterion. If not, the
 * program is undefined. Per default, the predefined sorting criterion std::less is used. If we use our
 * sorting criterion, it has to obey the strict weak ordering. If not, the program is undefined.
 * 
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::cout << std::boolalpha << std::endl;

    std::vector<int> vec{4, 3, 2, 1, 5, 6, 7, 9, 10};
    std::cout << "vec contains: " << vec << std::endl;
    std::cout << std::endl;
    
    std::make_heap(vec.begin(), vec.end());
    std::cout << "vec heap: " << vec << std::endl;
    std::cout << std::endl;
    
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << "\n";
    std::cout << std::endl;
    
    vec.push_back(100);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << "\n";
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): "
        << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;
    auto it = std::is_heap_until(vec.begin(), vec.end());
    std::cout << "This value is at index: " << std::distance(vec.begin(), it) << std::endl;
    std::cout << std::endl;
    
    std::push_heap(vec.begin(), vec.end());
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << "\n";
    std::cout << "vec contains: " << vec << std::endl;
    std::cout << std::endl;
    
    std::pop_heap(vec.begin(), vec.end());
    std::cout << "vec contains: " << vec << std::endl;
    std::cout << std::endl;
    
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): "
        << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;
    vec.resize(vec.size() - 1);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << "\n";
    std::cout << std::endl;
    
    std::cout << "vec.front(): " << vec.front() << std::endl;

    return 0;
}
