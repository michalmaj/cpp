/*
 * In this challenge, you are given the total number of seconds (3870), and your task is to
 * display the number of hours, minutes, and secods in it.
*/

#include <iostream>

int main(){
    int total_seconds = 3870;
    
    // Calculate minutes dividing total_seconds by 60
    int minutes = total_seconds / 60;
    
    // Calculate hours dividing minutes by 60
    int hours = minutes / 60;
    
    // Calculate rest of seconds subtracting minutes multiplies by 60 from total_seconds
    int seconds = total_seconds - minutes * 60;
    
    // Calculate rest of minutes subratcting hours multiplies by 60 from minutes.
    minutes -= hours * 60;
    
    
    std::cout << "Hours: " << hours << ", minutes: " << minutes
    << ", seconds: " << seconds << std::endl; 


    return 0;
}
