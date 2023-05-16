/*
 * To access the member of the structure variable, we write the name of the structure variable, followed
 * by a dot operator, which is further followed by the name of the memebr. To assign a value to the
 * member variable, we use the assignemnt operator followed by the value and the semicolon.
*/
#include <iostream>

struct Student{
    std::string name;
    int roll_number;
    int marks;
};

int main(){
    Student s1, s2, s3;
    
    // Assign value to memebrs of s1
    s1.name = "John";
    s1.roll_number = 1;
    s1.marks = 50;
    // Print members of s1
    std::cout << "Name: " << s1.name <<
    ", roll number: " << s1.roll_number <<
    ", marks: " << s1.marks << ".\n";
    
    // Assign value to memebrs of s2
    s2.name = "Alice";
    s2.roll_number = 2;
    s2.marks = 43;
    // Print members of s2
    std::cout << "Name: " << s2.name <<
    ", roll number: " << s2.roll_number <<
    ", marks: " << s2.marks << ".\n";
    
    /*
     * As we can see, setting each member of the structure variable is a tedious task. So, is there a way
     * to set all the memebrs of structure variables in one line?
     * Yes, ther is. We can initialize structure variables in one line using the initializer list.
     * In this case we will assign a comma-separated list of values enclosed is a curly bracket to the
     * structure variable. The first member will be assigned the first value in the curly bracket, the
     * second member will be assigned the second value, and so on.
     * Note: If the initializer list does not have some member of structure variables, those members are
     * autmatically initialized to their default value.
    */
    s3 = {"Michael", 7, 100};
    // Print members of s3
    std::cout << "Name: " << s3.name <<
    ", roll number: " << s3.roll_number <<
    ", marks: " << s3.marks << ".\n";

    return 0;
}
