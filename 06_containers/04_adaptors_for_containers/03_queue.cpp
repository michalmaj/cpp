/*
 * The std::queue follows the FIFO principle (First In First Out). The queue que, which needs the header
 * <queue>, has four special methods.
 * With que.push(e) we can insert an element e at the end of the queue and remove the first element from
 * the queue with que.pop(). que.back() enables us to refere to the last element in the que, que.front() to
 * the first element in the que. std::queue has similar characteristics as std::stack. So we can compare
 * std::queue instances and get thier sizes. The operations of the queue have constant complexity.
*/
#include <iostream>
#include <queue>

int main(){
    std::cout << std::boolalpha;

    std::queue<int> myQue;
    std::cout << "myQue.empty(): " << myQue.empty() << std::endl;
    std::cout << "myQue.size(): " << myQue.size() << std::endl;
    
    std::cout << std::endl;
    
    // Add some elements
    myQue.push(1);
    myQue.push(2);
    myQue.push(3);
    
    // Print front and back element
    std::cout << "myQue.front(): " << myQue.front() << std::endl;
    std::cout << "myQue.back(): " << myQue.back() << std::endl;
    
    // Print all elements (after that operation myQue will be empty!)
    while(!myQue.empty()){
        std::cout << myQue.front() << " "; // 1 2 3
        myQue.pop(); 
    }
    
    std::cout << std::endl << std::endl;
    
    std::cout << "myQue.empty(): " << myQue.empty() << std::endl;
    std::cout << "myQue.size(): " << myQue.size() << std::endl;


    return 0;
}
