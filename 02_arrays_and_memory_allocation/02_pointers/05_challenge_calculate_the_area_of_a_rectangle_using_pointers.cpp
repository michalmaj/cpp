/*
 * Your task is to write a function area. In the functon parameter, you will pass the three pointers
 * of type in its input parameters.
 * void area(double* length, double* width, double* result);
 * Your functon should calculate the area of the rectangle and store the output in the result.
*/

#include <iostream>

void area(double* length, double* width, double* result){
    *result = (*length) * (*width);
}

int main(){
    double length = 4.5, width = 6.7, result = 0;
    
    area (&length, &width, &result);
    
    std::cout << "Result: " << result << "\n";


    return 0;
}
