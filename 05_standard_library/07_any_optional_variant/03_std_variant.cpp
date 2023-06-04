/*
 * std::variant allows us to create a variable from any of types specified in the std::varian container.
 * std::variant is a type-safe union. An instance of std::variant has a value from one of its types. The 
 * type must not be a reference, array or void. A std::variant can have a type more than once. A default
 * initialised std::variant is initialised with its first type; therefore, its first type must have a 
 * default constructor. By using var.index we get the zero-based index of the alternative held by the 
 * std::variant var.
 * var.valueless_by_exception returns false if the variant holds a value. By using var.emplace we can create
 * a new value in-place. There are a few global functions used to access a stdLLvariant. The function 
 * template var.holds_alternative lets us check if the std::variant holds a specified alternative. We can
 * use std::get with an index and with a type as argument. By using an index, we will get the value. If we
 * invoke std::get with a type, we only will get the value if it is unique. If we use an invalid index or a 
 * non-unique type, we will get a std::bad_variant_access exception. In contrast to std::get which 
 * eventually returns an exception, std::get_if returns a null pointer in the case of an error.
*/

#include <iostream>
#include <variant>
#include <cassert>

int main(){
    // v and w are two variants. Both can have an int and a float value. Their default value is 0
    std::variant<int, float> v, w;
    
    // v becomes 12 and the following call std::get<int>(v) returns the value.
    v = 12; // v contains 12
    int i = std::get<int>(v);
    
    // The next three lines show three possibilities to assign the variant v to w, byt we have to keep
    // a few rules in mind. The type must be unique and the index valid.
    w = std::get<int>(v);
    w = std::get<0>(v); // same effect as the previous line
    w = v; // same effect as the previous line
    
//    std::get<double>(v); // CE: no double in [int, float]
//    std::get<3>(v); // CE: valid index values are 0 and 1

    try{
        std::get<float>(w); // w contains int, not float: will throw
    }catch(const std::bad_variant_access& e){
        std::cout << e.what() << std::endl;
    }
    
    std::variant<std::string> x{"abc"}; // Converting constructors work when unambiguous
    x = "def"; // Converting assignment also works when unambiguous
    std::cout << std::get<std::string>(x) << std::endl;
    
    std::variant<std::string, bool> y{"abc"}; // casts to bool when passed a char const*
    y = true;
    assert(std::holds_alternative<bool>(y)); // Succeeds
    y = "xyz";
    assert(std::holds_alternative<std::string>(y));
    
    return 0;
}
