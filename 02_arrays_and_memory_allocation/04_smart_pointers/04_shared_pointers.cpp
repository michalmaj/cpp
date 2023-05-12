/*
 * std::shared_ptr shares ownership of the resource. They have two handles: one for the resource, and one
 * for the reference counter. By copying std::shared_ptr, the reference count is increased by one. It is
 * decreased by one if the std::shared_ptr goes out of scope. If the reference counter becomes the value 0,
 * the C++ runetime automatically releases the resource, since there is no longer an std::shared_ptr
 * referencing the resource. The release of the resource occurs exactly when the last std::shared_ptr
 * referencing the resource. The C++ runtime guarantees that the call of the reference counter is an atomic
 * operation. Due to ths management, std::shared_ptr consumes more time and memory than a raw pointer or
 * std::unique_ptr.
 *
 * Let's check some methods:
 *  - get - return a pointer to the resource.
 *  - get_deleter - return the delete function.
 *  - reset - reset the resource.
 *  - swap - swap the resource.
 *  - unique - check if the std::shared_ptr is the exclusive owner of the resource.
 *  - use_count - return the value of the reference counter.
 *
 * The helper function std::make_shared creates the resource and returns it in an std::shared_ptr. Use
 * std::make_shared rather than directly creating an std::shared_ptr because std::make_shared is much 
 * faster. Additionally, such as in the case of std::make_unique, std::make_shared guarantees no memory
 * leaks.
 *
 * std::share_ptr from this - the unique technique, in which a class derives from a class template having
 * itself as a parameter, is called CRTP and stands for Curiously Recurring Template Pattern.
 * Usng the class std::enable_shared_from_his, we can create objects that return an std::shared_ptr to
 * themselves. To do so, we must publicly derive the class from std:enable_shared_from_ths. So the class
 * will be support the method shared_from_this, and return std::shared_ptr
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
    std::shared_ptr<ShareMe> shareMe{std::make_shared<ShareMe>()};
    std::shared_ptr<ShareMe> shareMe1 = shareMe->getShared();
    
    {
        auto shareMe(shareMe1);
        std::cout << "shareMe.use_count(): " << shareMe.use_count() << std::endl;
    }
    
    std::cout << "shareMe.use_count(): " << shareMe.use_count() << std::endl;
    
    shareMe1.reset();
    
    std::cout << "shareMe.use_count(): " << shareMe.use_count() << std::endl;
    
    std::cout << std::endl;


    return 0;
}
