/*
 * The structure is a user-defined data type that is used to store variables or arrays of different data
 * types under a single name.
 * To define a structure in a program, use the struct keyword followed by a structure name, which is
 * followed by curly braces and a semicolon at the end. Inside the curly braces, we declare the data 
 * members of the structure.
 * Note: Forgetting a semicolon after the structure definition generates an error.
 *
 * Example:
 * Suppose that we want to store the record of student name, roll number, and marks in a single location.
 * Let's see in the example below how a struct can help us.
*/

#include <iostream>

struct Student{
    std::string name;
    int roll_number;
    int marks;
};

int main(){


    return 0;
}
