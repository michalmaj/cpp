#include <iostream>
#include <memory>

struct MyInt{
    MyInt(int v) : val(v){
        std::cout << "Hello: " << val << std::endl;
    }
    
    ~MyInt(){
        std::cout << "Good bye: " << val << std::endl;
    }
    
    int val;
};

int main(){
    std::shared_ptr<MyInt> sp(new MyInt(99));
    
    std::cout << "My value: " << sp->val << std::endl;
    std::cout << "Use count: " << sp.use_count() << std::endl;
    
    {
        std::shared_ptr<MyInt> lsp(sp);
        std::cout << "Use count: " << lsp.use_count() << std::endl; 
    }
    
    std::cout << "Use count: " << sp.use_count() << std::endl;
    
    std::shared_ptr<MyInt> sp1(sp);
    std::cout << "Use count: " << sp.use_count() << std::endl;
    sp1.reset();
    std::cout << "Use count: " << sp.use_count() << std::endl;
    
    sp = std::make_shared<MyInt>(11);
    
    


    return 0;
}
