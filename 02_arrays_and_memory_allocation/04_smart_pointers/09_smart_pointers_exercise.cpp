/*
 * Implement the class ShareMe so the objects of type ShareMe return an std::shared_ptr to themselves.
*/
#include <iostream>
#include <memory>

class ShareMe: public std::enable_shared_from_this<ShareMe>{
public:
    std::shared_ptr<ShareMe> getShared(){
        return shared_from_this();
    }
};

int main(){
    //share the same ShareMe object
    auto shareMe1 = std::make_shared<ShareMe>();
    auto shareMe2 = shareMe1->getShared();
    
    // Both resource have the same address
    std::cout << "Address of resource of shareMe1 " << shareMe1.get() << std::endl;
    std::cout << "Address of resource of shareMe2 " << shareMe2.get() << std::endl;
    
    // The use_count is 2
    std::cout << "shareMe1.use_count(): " << shareMe1.use_count() << std::endl;

    return 0;
}
