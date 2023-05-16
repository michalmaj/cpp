/*
 * The pointer that stores the address of the structure variable is known as a structure pointer.
 * We can access members of structure through a structure pointer in two ways:
 *  1. Indirection and the dot operator.
 *  2. Arrow operator.
 *
 * Indirection and dot operator
 * To access the members of the structure variable to which the structure pointer is pointing, we will first
 * use the dereference operator (*) with a structure pointer, which is followed by the dot operator and the
 * memebr whose value you want to access. In addition it is necessary to put brackets around the asterisk,
 * which is followed by a dot operator and a structure memebr
 *
 * Arrow operator
 * To access the structure members using the arrow operator, we have to write the name of the structure
  * pointer followed by an arrow operator, which is further followed by a structure memeber and semicolon.  
*/
#include <iostream>

 #include <iostream>
 
 struct Student{
    std::string name;
    int roll_number;
    int marks;
};

int main(){
    // 1. Version with dot operator 
    // Declare structure variable
    Student s1;    
    // Declare structure pointer and store address of structure variable in structure pointer.
    Student* ptrs1 = &s1;   
    // Set value of name
    (*ptrs1).name = "John";
    // Set value of roll_number
    (*ptrs1).roll_number = 1;
    // Set value of marks
    (*ptrs1).marks = 50;    
    // Print info about student
    std::cout << "Name: " << (*ptrs1).name <<
    ", roll number: " << (*ptrs1).roll_number <<
    ", marks: " << (*ptrs1).marks << ".\n";
    
    // 2. Version with arrow operator
    //Declare structure variable
    Student s2;
    // Declare structure pointer and store address of structure varaible in structure pointer
    Student* ptrs2 = &s2;
    // Set value of name
    ptrs2->name = "Alice";
    // Set value of roll_number
    ptrs2->roll_number = 2;
    // Set value of marks
    ptrs2->marks = 53;
    // Print info about student
    std::cout << "Name: " << ptrs2->name <<
    ", roll number: " << ptrs2->roll_number <<
    ", marks: " << ptrs2->marks << ".\n";

    return 0;
}
