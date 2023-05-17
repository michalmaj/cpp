/*
 * Your task is to subtract two complex numbers.
 *
 * What is a complex number?
 * A complex number is a number with both real and imaginary parts. For example we have: x + yi, where
 * x is real part of complex number, y is imaginary part of the complex number, i is sqrt(-1).
 *
 * To store the complex number, we can defined the structure complex_number.
 * To subtract the complex number, we will follow the following streps:
 *  - Subtract a real part of the second complex number from the real part of the firest complex number.
 *  - Then subtrack imaginary part of the second complex number from the imaginary part of a first 
 *    complex number.
*/

#include <iostream>

// Structure to store complex number
struct complex_number {
  double real;
  double imaginary;
};

// Functon to subtract two complex numbers
complex_number subtract(const complex_number& c1, const complex_number& c2){
    complex_number result;
    // Subtract real parts
    result.real = c1.real - c2.real;
    // Subtract imaginary parts
    result.imaginary = c1.imaginary - c2.imaginary;
    
    // Return structure variable
    return result;
}

void print_complex_number(const complex_number& c){
    std::cout << c.real << " + " << c.imaginary << "i\n";
}

int main(){

    auto result = subtract({12.3, 67.4}, {54.2, 90.8});
    print_complex_number(result);

    return 0;
}
