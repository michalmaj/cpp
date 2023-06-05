/*
 * std::deque (double ended queue), which consist of a sequence of arrays, is quite similar to std::vector.
 * std::deque needs the header <deque>. The std::deque has three additional methods deq.push_front(elem),
 * deq.pop_front(), and deq.emplace_fron(args...) to add or remove elements at the beginning.
 *
 *  Criteria                                Dequeue
 *  Size                                    dynamic
 *  Implementation                          sequence of arrays
 *  Access                                  random
 *  Optimized for insert and delete at      begin and end: O(1)
 *  Memory reservation                      no
 *  Release Memory                          shrink_to_fit
 *  Strength                                insertion and deletion at the begin and end
 *  Weakness                                Insertion and deletion at an arbitrary position: O(n)
*/
#include <iostream>
#include <deque>
#include <ranges> // -std=c++20

class MyInt{
private:
    int myInt;
    
public:
    MyInt(int i): myInt(i) {}
    
    friend std::ostream& operator<<(std::ostream& out, const MyInt& m){
        out << m.myInt;
        return out;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& d){
    for(const auto& e : d)
        std::cout << e << " ";
    return out;
}

int main(){
    std::deque<MyInt> myIntDeq;
    
    myIntDeq.push_back(MyInt(5)); // add one elelemnt at the end
    myIntDeq.emplace_back(1); // add another element at the end
    std::cout << "myIntDeq.size(): " << myIntDeq.size() << std::endl;
    std::cout << "myIntDeq contains: " << myIntDeq << std::endl;
    
    std::deque<MyInt> intDeq;
    intDeq.assign({1, 2, 3}); // add 3 elements to deque
    std::cout << "intDeq contains: " << intDeq << std::endl;
    
    // Add an element at the begin
    intDeq.insert(intDeq.begin(), 0);
    std::cout << "intDeq contains: " << intDeq << std::endl;
    
    // Add an element at index 4
    intDeq.insert(intDeq.begin() + 4, 4);
    std::cout << "intDeq contains: " << intDeq << std::endl;
    
    // Add some elements at the end
    intDeq.insert(intDeq.end(), {5, 6, 7, 8, 9, 10, 11});
    std::cout << "intDeq contains: " << intDeq << std::endl;
    
    // Print i reverse order
    for(auto revIt = intDeq.rbegin(); revIt != intDeq.rend(); ++revIt)
        std::cout << *revIt << " ";
    std::cout << std::endl;
    
    // Print in reverse order using views
    for(auto& e : intDeq | std::views::reverse)
        std::cout << e << " ";
    std::cout << std::endl;
    
    // Remove element from the end
    intDeq.pop_back();
    std::cout << "intDeq contains: " << intDeq << std::endl;
    
    // Add an element at the begin
    intDeq.push_front(-1);
    std::cout << "intDeq contains: " << intDeq << std::endl;
    

    return 0;
}
