/*
 * Implement the class ShareMe so the objects of type ShareMe return an std::shared_ptr to themselves.
*/
#include <iostream>
#include <memory>

// With the class std::enable_shared_from_this, we can create objects which return an std::shared_ptr on
// itself. For that, we must derive the class public from std::enable_shared_from_this.
class ShareMe: public std::enable_shared_from_this<ShareMe>{
public:
    std::shared_ptr<ShareMe> getShared(){
        return shared_from_this();
    }
};

int main(){
    //share the same ShareMe object
    auto shareMe1 = std::make_shared<ShareMe>();
    
    // The smart pointer shareMe1 is copied by shareMe. The call shareMe->getShared() 
    // creates new smart pointer. get_shared() internally uses the function shared_from_this.
    auto shareMe2 = shareMe1->getShared();
    
    // Both resource have the same address
    std::cout << "Address of resource of shareMe1 " << shareMe1.get() << std::endl;
    std::cout << "Address of resource of shareMe2 " << shareMe2.get() << std::endl;
    
    // The use_count is 2
    std::cout << "shareMe1.use_count(): " << shareMe1.use_count() << std::endl;

    return 0;
}
