/*
 * The constructor is used to constuct the object of a class. It is a special member function that outlines
 * the steps that are performaed when an instance of a class is created in the program.
 * A constructor's name must be exactly the same as the name of its class.
 * The constructor is a special function because it does not have a return type. We do not even need to
 * write void as the return type. It is  a good practice to declare/define it as the first member function.
 *
 * Default Constructor
 * The default constructor is the most basic form of a constructor. In a default constructor, we define the
 * default values for the data members of the class. Hence, the constructor creates an object in which the
 * data members are initialized to their default values.
 * The default constructor does not need to be explicitly defined. Even if we don't create it, the C++ 
 * compiler will call a default constructor and set data members to some junk values.
 *
 * Parametrized Constructor
 * In a parametrized constructor, we pass arguments to the constructor and set them as the values of our
 * data members. We are basically overriding the default constructor to accomodate our preferred values for
 * the data members.
 *
 * this Pointer
 * The this pointer points to the calling object itself. We can use this pointer to access a data member of
 * the calling object. The expression this->memberName specifies that we are accessing the memberName.
 * Note: Since this is a pointer, we use the -> operator to access members instead. 
*/
#include <iostream>
#include <string>

class Date{
    int day;
    int month;
    int year;
    
public:
    // Default constructor
    Date(){
        // We must define the default values for day, month, and year
        day = 0;
        month = 0;
        year = 0;
    }
    
    // Parametrized constructor
    //Date(int d, int m, int y){
        //// The arguments are used as values
        //day = d;
       // month = m;
        //year = y;
    //}
    
    // Parametrized constructor - same version as above, but we are using this pointer
    Date(int day, int month, int year){
        // The arguments are used as values
        this->day = day;
        this->month = month;
        this->year = year;
    }
    
    // A simple print function
    void printDate(){
        std::cout << "Date: " << day << "/" << month << "/" << year << "\n";
    }
};


int main(){
    // Call the Date constructor to create its object
    Date d1;
    d1.printDate();
    
    // Create object using parametrized constructor
    Date d2(19, 5, 2023);
    d2.printDate();


    return 0;
}
