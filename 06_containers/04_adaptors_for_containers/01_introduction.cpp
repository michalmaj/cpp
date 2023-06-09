/*
 * C++ has with std::stack, std::queue and std::priority_queue three special sequnetial containers.
 * The adaptors for containers:
 *  - support a reduced interface for existing sequentail containers,
 *  - can not be used with algorithms of the STL,
 *  - are class templates which are parametrised by their data type and theri container (std::vector, 
 *    std::list and std::deque),
 *  - use by default std::deque as the internal sequental container.
*/
#include <iostream>
#include <queue>
#include <stack>
#include <concepts> // -std=c++20

template <typename T>
concept adaptors = 
    std::same_as<T, std::stack<typename T::value_type, typename T::container_type>> ||
    std::same_as<T, std::priority_queue<typename T::value_type, typename T::container_type,
                                        typename T::value_compare>>;
template <typename T>
concept queue = 
        std::same_as<T, std::queue<typename T::value_type, typename T::container_type>>;

template <adaptors T>
std::ostream& operator<<(std::ostream& out, T t){ // Pass by value (copy, without changing elements)
    while(!t.empty()){
        out << t.top() << " ";
        t.pop();
    }
    return out;
} 

template <queue T>
std::ostream& operator<<(std::ostream& out, T t){ // Pass by value (copy, without changing elements)
    while(!t.empty()){
        out << t.front() << " ";
        t.pop();
    }
    return out;
}

template <typename T>
concept seq = 
    std::same_as<T, std::initializer_list<typename T::value_type>>;

template <seq T>
std::ostream& operator<<(std::ostream& out, const T& t){ 
    for(const auto& e : t)
        out << e << " ";
    return out;
}

int main(){
    std::stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "intStack contains: " << intStack << std::endl;
    
    std::queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);
    std::cout << "intQueue contains: " << intQueue << std::endl;
    
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    std::cout << "data contains: " << data << std::endl;
    
    // std::vector<int>, std::greater<int> - to get min priority queue
    std::priority_queue<int> intPriorityQueue; // Max priority queue
    for (int n : data)
        intPriorityQueue.push(n);
    std::cout << "intPriorityQueue contains: " << intPriorityQueue << std::endl;

    return 0;
}
