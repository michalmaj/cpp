/*
 * We can define a function in which we just pass the structure variable, and it prints the value for us.
 * Note: So far, we have not seen a way to return multiple variables of different data types from a 
 * function. By returning a structure from a function, we can return multiple variables of different data
 * types.
*/
 #include <iostream>
 
 struct Student{
    std::string name;
    int roll_number;
    int marks;
};

// Helper function to fill student
Student fillStudent(std::string name, int roll_number, int marks){
    Student s;
    s.name = name;
    s.roll_number = roll_number;
    s.marks = marks;
    
    return s;
}

// Helper function for printing student
void printStudent(const Student& s){
    // Print info about student at index
    std::cout << "Name: " << s.name <<
    ", roll number: " << s.roll_number <<
    ", marks: " << s.marks << ".\n";
}
 
 int main(){
     // We declare an array named s with a capacity to store 100 structure variables os Student
    Student s[100];
    
    // Assign value for student at index 0
    s[0] = {"John", 1, 50};
    printStudent(s[0]);
    
    
    // Assign value for student at index 1
    s[1] = {"Alice", 2, 43};
    printStudent(s[1]);
    
    // Assigne value for student at index 2 using functon fillStudent
    s[2] = fillStudent("Michael", 7, 100);
    printStudent(s[2]);
    
        
 
    return 0;
 }
