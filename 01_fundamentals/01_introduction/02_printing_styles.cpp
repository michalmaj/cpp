#include <iostream>

int main(){
    // Output will be in the same line
    std::cout << "Hello ";
    std::cout << "World!";

    // But we can move World! to the new line using std::endl
    std::cout << std::endl; // Adds a new line
    std::cout << "Hello " << std::endl;
    std::cout << "World!" << std::endl;

    return 0;
}
