/*
 * Your task is to write a function average. Your function signature should be:
 * double average(double marks[], int size);
 * The input array marks[] will contain the marks of all students in the class. Your task is to calculate
 * the average marks of the class and return it in the output. It is assumed that the value of size will
 * be greater than zero.
 * Sample input: double marks[]{10.5, 67.8, 98.6, 31.2}; 
*/

double average(double marks[], int size){
    double average = 0;
    for(int i = 0; i < size; ++i)
        average += marks[i] / size;
  
    return average; 
}

#include <iostream>

int main(){
    
    double marks[]{10.5, 67.8, 98.6, 31.2}; 
    int size = std::size(marks);
    
    std::cout << "Average: " << average(marks, size) << "\n";

    return 0;
}
