/*
 * Function overloading is the concept of affecting a function's behavior based on the number of
 * parameters or their types.
 * This way, functions with different parameters can coexist with the same name. Function
 * overloading works with different parameters. The function prototype can change and return
 * type changes according to parameters being returned.
 *
 * Rules for choosing the right function:
 *  - We need to search for a functon with the exact type;
 *  - We need to apply type promotion to the arguments.
 *  - We need to convert arguments.
 *
 * Note:
 * min(int x, int y) is the same as min(int& x, int& y)
 * The same is apply to the const and volatile qualifiers.
*/

#include <iostream>
#include <cstring>

// The below min function behaves differently based on the types of arguments provided.
const char* min(const char* s, const char* t){
    return (strcmp(s, t) < 0) ? s : t;
}
float min(float x, float y){
    return (x < y)? x : y;
}
// Now, the function can handle three float arguments as well. We can extend this to as many
// as we want.
float min(float x, float y, float z){
    return (x < y)? (x < z ? x : z) : (y < z? y : z);
}

int main(){
    // Example with const char*
    const char* s = min("abc", "xyz");
    std::cout << s << "\n";
    
    // Example with min(float, float)
    float f1 = min(1.2, 2.3);
    std::cout << f1 << "\n";
    
    // Example with min(float, float, float)
    std::cout << min(1, 2, -1) << "\n";

    return 0;
}
