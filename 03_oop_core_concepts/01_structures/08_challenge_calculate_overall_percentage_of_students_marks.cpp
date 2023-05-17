/*
 * In this challenge, you will be given the marks of a student in 4 subjects out of 100. Your task is to
 * calculate the overall percentage of the student. The basic formula for calculating the percentage is
 * given below:
 *  Percentage = (Marks Obtained / Total Marks) * 100
 * Since there are 4 subjects and each subject will be of 100 marks, the total marks will be 400.
*/
#include <iostream>

// Structure to store Student information
struct Student {
    std::string name;
    double marks[4];
};

// Function to calculate percentage
double calculate_percentage(struct Student s) {
    double percentage = 0;
    
    for(int i{0}; i < 4; ++i)
        percentage += s.marks[i] / 4;
    
    return percentage;
}

int main(){
    auto result = calculate_percentage({"John", {30.500000 , 49.700000 , 22.300000 , 32.900000}});
    std::cout << "Percentafe for student is: " << result << std::endl;
    
    result = calculate_percentage({"Alex", {90.000000 , 87.000000 , 99.600000 , 82.000000}});
    std::cout << "Percentafe for student is: " << result << std::endl;
    
    result = calculate_percentage({"Kim", {45.900000 , 63.000000 , 42.000000 , 71.000000}});
    std::cout << "Percentafe for student is: " << result << std::endl;
    
    result = calculate_percentage({"Tom", {22.000000 , 29.500000 , 13.000000 , 33.200000}});
    std::cout << "Percentafe for student is: " << result << std::endl;

    return 0;
}
