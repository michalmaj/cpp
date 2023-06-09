/*
 * The std::stack follows the LIFO principle (Last In First Out). The stack sta, which needs the header
 * <stack> has three special method.
 * With sta.push(e) you caninsert a new element e at the top of the stack, remove it from the top with
 * sta.pop() and reference it with sta.top(). The stack supports the comparasion operators and knows its
 * size. The operations of the stack have constants complexity.
*/
#include <iostream>
#include <stack>

int main(){
    std::cout << std::boolalpha;
    
    std::stack<int> myStack;
    std::cout << "myStack.empty(): " << myStack.empty() << std::endl; // true
    std::cout << "myStack.size(): " << myStack.size() << std::endl; // 0

    std::cout << std::endl;

    // Add elements to the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    
    std::cout << "myStack.top(): " << myStack.top() << std::endl; // 3
    
    std::cout << std::endl;
    
    // Print all elements (but after that mySTack will be empty!)
    while(!myStack.empty()){
        std::cout << myStack.top() << " "; // 3 2 1
        myStack.pop();
    }

    std::cout << std::endl << std::endl;

    std::cout << "myStack.empty(): " << myStack.empty() << std::endl; // true
    std::cout << "myStack.size(): " << myStack.size() << std::endl; // 0

    return 0;
}
