/*
 * std::weak_ptr is not a classic pointer, since it supports no transparen access to the resource;
 * it only borrows the resource from an std::shared_ptr.
 * There is one main reason for thr existence and use of std::weak_ptr. It breaks the cycle of
 * std::shared_ptr.
 *
 * Overview of the methods of std::weak_ptr:
 *  expired - check if the resource was deleted.
 *  lock - create a std::shared_ptr on the resource.
 *  reset - reset the resource.
 *  swap - swap resources.
 *  use_count - return the value of the reference counter.
*/
#include <iostream>
#include <memory>

int main(){
    std::cout << std::boolalpha;
    
    auto sp = std::make_shared<int>(11);
    // We create an std::weak_ptr that borrows the resource from the std::shared_ptr
    std::weak_ptr<int> wp(sp);
    
    // THe output in this case is 1, because std::weak_ptr doesn't increment the counter.
    std::cout << "wp.use_count(): " << wp.use_count() << std::endl;
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;
    
    // The call an expired() method check if the resource was already deleted.
    std::cout << "wp.expired(): " << wp.expired() << std::endl;
    
    if(std::shared_ptr<int> sp1 = wp.lock()){
        std::cout << "*sp: " << *sp << std::endl;
        std::cout << "sp1.use_count(): " << sp1.use_count() << std::endl;
    }
    else{
        std::cout << "Don't get the resource!\n";
    }
    
    wp.reset();
    
    if(std::shared_ptr<int> sp1 = wp.lock()){
        std::cout << "*sp: " << *sp << std::endl;
        std::cout << "sp1.use_count(): " << sp1.use_count() << std::endl;
    }
    else{
        std::cout << "Don't get the resource!\n";
    }


    return 0;
}
