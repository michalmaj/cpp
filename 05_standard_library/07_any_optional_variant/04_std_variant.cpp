/*
 * std::variant has an interesting non-member function std::visit that allows us to execute a callable on a
 * list of variants. A callable is something which we can invokde. Typically this can be a function, a 
 * function object, or lambda expression. For simplicity reasons, we use a lambda function in this example.
*/
#include <iostream>
#include <variant>
#include <vector>

int main(){
    std::vector<std::variant<char, long, float, int, double, long long>>
        vecVariant = {5, '2', 5.4, 100ll, 2023l, 3.5f, 2020};
       
    for(auto& v : vecVariant){
        std::visit([](auto&& arg){std::cout << arg << " ";}, v);
    }
    
    std::cout << std::endl;
    
    // Display each type
    std::common_type<char, long, float, int, double, long long>::type res{};
    
    std::cout << typeid(res).name() << std::endl; // d (for double)
    
    for(auto& v : vecVariant){
        std::visit([&res](auto&& arg){res += arg;}, v);
    }
    std::cout << "res: " << res << std::endl;
    
    // Double each value
    for(auto& v : vecVariant){
        std::visit([](auto&& arg){arg *= 2;}, v);
        std::visit([](auto&& arg){std::cout << arg << " ";}, v);
    }
    std::cout << std::endl;

    return 0;
}
