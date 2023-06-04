/*
 * To access the elements of a container, we can use an iterator. A begin and end iterator forms a range,
 * which can be processed further. For a container cont, cont.begin() is the begin iterator and cont.end()
 * is the end iterator, which defines a half-open range. It is half-open because the begin iterator belongs 
 * to the range, the end iterator refers to a position past the range. With the iterator pair cont.begin()
 * and cont.end() we can modify the elements.
 *  Iterator                                        Description
 *  begin() and end()                               Pair of iterators to iterate forward.
 *  cbegin() and cend()                             Pair of iterators to iterate const forward.
 *  rbegin() and rend()                             Pair of iterators to iterate backward.
 *  crbegin() and crend()                           Pair of iterators to iterate const backward.
*/
#include <iostream>
#include <vector>
#include <ranges>

struct MyInt{
    MyInt(int i): myInt(i) {}
    int myInt;
    friend std::ostream& operator<<(std::ostream& out, const MyInt& m);
};

std::ostream& operator<<(std::ostream& out, const MyInt& m){
    out << m.myInt;
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<MyInt> myIntVec{MyInt(9)};
    myIntVec.push_back(5);
    myIntVec.emplace_back(1);
    
    std::cout << "myIntVec.size(): " << myIntVec.size() << std::endl; // 3
    std::cout << "myIntVec contains: " << myIntVec << std::endl;
    
    std::vector<int> intVec;
    intVec.assign({1, 2, 3});
    std::cout << "intVec contains: " << intVec << std::endl;
    
    // Insert element at the beginning
    intVec.insert(intVec.begin(), 0);
    std::cout << "intVec contains: " << intVec << std::endl;
    
    // Insert element at index 4
    intVec.insert(intVec.begin() + 4, 4);
    std::cout << "intVec contains: " << intVec << std::endl;
    
    // Insert many elements at the end
    intVec.insert(intVec.end(), {5, 6, 7, 8, 9, 10, 11});
    std::cout << "intVec contains: " << intVec << std::endl;
    
    // Print elements in reverse order
    for(auto revIt = intVec.rbegin(); revIt != intVec.rend(); ++revIt)
        std::cout << *revIt << " ";
    std::cout << std::endl;
    
    // Print elements in reverse order (since C++20)
    for(const auto& e : intVec | std::views::reverse)
        std::cout << e << " ";
    std::cout << std::endl; 
    
    
    // Remove last element
    intVec.pop_back();
    std::cout << "intVec contains: " << intVec << std::endl;
    

    return 0;
}
