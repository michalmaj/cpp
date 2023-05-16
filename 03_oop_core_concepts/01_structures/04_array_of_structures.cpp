/*
 * We have 100 students in a class, and we have to store the name, age, and roll_number of each student,
 * which means we need 300 variables. We have found a way to sotre all these variables under a single name.
 * However, to store data for each student in the class, we still have to declare 100 structure variales.
 * Declaring 100 structure variables and then keeping track of them is quite difficult.
 * Here, an array of structures comes in handy. In C++, each element of a structure array represents a
 * structure variable.
*/
#include <iostream>

struct Student{
    std::string name;
    int roll_number;
    int marks;
};

int main(){
    // We declare an array named s with a capacity to store 100 structure variables os Student
    Student s[100];
    
    // Assign value for student at index 0
    s[0] = {"John", 1, 50};
    
    // Print info about student at index 0
    std::cout << "Name: " << s[0].name <<
    ", roll number: " << s[0].roll_number <<
    ", marks: " << s[0].marks << ".\n";
    
    // Assign value for student at index 1
    s[1] = {"Alice", 2, 43};
    
    // Print info about student at index 1
    std::cout << "Name: " << s[1].name <<
    ", roll number: " << s[1].roll_number <<
    ", marks: " << s[1].marks << ".\n";


    return 0;
}
