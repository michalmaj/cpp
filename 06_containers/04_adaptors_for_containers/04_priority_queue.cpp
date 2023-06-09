/*
 * The std::priority_queue is a reduced std::queue. It needs the header <queue>.
 * The difference to the std::queue is, that thier biggest element is always at the top of the priority
 * queue. std::priority_queue pri uses by default the comparison operator std::less. Similar to std::queue,
 * pri.push(e) inserts a new element e into the priority queue. pri.pop() removes the first element of the
 * pri, but does that with logarithmic complexity. With pri.top() we can reference the first element in the
 * priority queue, which is the greatest one. The std::priority_queue knows its size, but didn't support the
 * comparison operator on their instances.
*/
#include <iostream>
#include <queue>
#include <vector>

int main(){
    std::cout << std::boolalpha;
    
    std::priority_queue<int> myPriorityQueue;
    std::cout << "myPriorityQueue.empty(): " << myPriorityQueue.empty() << std::endl;
    std::cout << "myPriorityQueue.size(): " << myPriorityQueue.size() << std::endl;
    
    std::cout << std::endl;
    
    // Add some elements
    myPriorityQueue.push(1);
    myPriorityQueue.push(2);
    myPriorityQueue.push(3);

    // Show top element
    std::cout << "myPriorityQueue.top(): " << myPriorityQueue.top() << std::endl;

    std::cout << std::endl;
    
    // Print all elements (after that operation myPriorityQueue will be empty!)
    while(!myPriorityQueue.empty()){
        std::cout << myPriorityQueue.top() << " "; // 3 2 1
        myPriorityQueue.pop();
    }
    
    std::cout << std::endl << std::endl;
    
    std::cout << "myPriorityQueue.empty(): " << myPriorityQueue.empty() << std::endl;
    std::cout << "myPriorityQueue.size(): " << myPriorityQueue.size() << std::endl;
    
    std::cout << std::endl << std::endl;
    
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> myPriorityQueue2;
    myPriorityQueue2.push("Only");
    myPriorityQueue2.push("for");
    myPriorityQueue2.push("testing");
    myPriorityQueue2.push("purpose");
    myPriorityQueue2.push(".");
    
    while(!myPriorityQueue2.empty()){
        std::cout << myPriorityQueue2.top() << " ";
        myPriorityQueue2.pop();
    }


    return 0;
}   
