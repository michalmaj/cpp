/*
 * The key question of the std::unique_ptr is when to delete the underluing resource. This occurs
 * when the std::unique_ptr goes out of scope or receices a new resource.
*/

#include <iostream>
#include <memory>
#include <utility>

struct MyInt{
    MyInt(int i) : i_(i) {}   
    ~MyInt(){
        std::cout << "Good bye from " << i_ << std::endl;
    }
    
    int i_;
};

int main(){
    std::cout << std::endl;
    
    // Create unique_ptr
    std::unique_ptr<MyInt> up1{new MyInt(19)};
    // Return address of the object or nullptr if no object s owned.
    std::cout << "up1.get(): " << up1.get() << std::endl;
    
    // Create new unique pointer and move data from up1 to up2
    std::unique_ptr<MyInt> up2;
    up2 = std::move(up1); // Since this line resource is keeping by up2
    // up1 is empty
    std::cout << "up1.get(): " << up1.get() << std::endl;
    std::cout << "up2.get(): " << up2.get() << std::endl;
    
    {
        // Unique pointer will be deleted outside this scope
        std::unique_ptr<MyInt> local_ptr = std::make_unique<MyInt>(777);
    }
    
    std::cout << std::endl;
    
    // We can reset unique pointer, wipe out data inside and give it a new data
    up2.reset(new MyInt(43));
    // New address
    std::cout << "up2.get(): " << up2.get() << std::endl; 
    
    // We can also return ownership to for example raw pointer
    MyInt* ptr = up2.release();
    std::cout << "ptr: " << ptr << std::endl;
    delete ptr;
    
    std::cout << std::endl;
    
    std::unique_ptr<MyInt> up3{std::make_unique<MyInt>(11)};
    std::unique_ptr<MyInt> up4{std::make_unique<MyInt>(55)};
    
    std::cout << "up3.get(): " << up3.get() << "\n";
    std::cout << "up4.get(): " << up4.get() << "\n";
    
    // Swap pointers
    std:swap(up3, up4);
    
    std::cout << "up3.get(): " << up3.get() << "\n";
    std::cout << "up4.get(): " << up4.get() << "\n";


    return 0;
}
