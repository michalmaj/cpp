/*
 * To declare a structure variable in a program, we write the name of the structure followed by the name of
 * a structure variable, which is further followed by a semicolon. 
*/
#include <iostream>

struct Student{
    std::string name;
    int roll_number;
    int marks;
};

int main(){
    // Declaration three structure variables s1, s2, s3 in a program.
    // The data type of theses variables is Student.
    Student s1, s2, s3;

    return 0;
}
