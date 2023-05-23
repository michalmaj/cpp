/*
 * By using these specifiers, we limit the access of the data members and member functions to the other 
 * classes and main.
 *
 * private Mode of Inheritance
 * By using private inheritance, the private data members and member functions of the base classes are
 * naccessible in the derived class. Protected and publc members of the base class are accessible to the
 * derived class and behave as private members of the derived class.
 * Note: any classes inheriting from the above-derived class remain unware (this is, do not have access) of
 * the base class.
*/
#include <iostream>

class Vehicle{
    std::string Make;
    std::string Color;
    int Year;
    
protected:
    std::string Model;
    
public:
    Vehicle(){
        Make = "";
        Color = "";
        Year = 0;
        Model = "";
    }
    Vehicle(std::string mk, std::string col, int yr, std::string mdl){
        Make = mk;
        Color = col;
        Year = yr;
        Model = mdl; 
    }
    
    void print_details(){
        std::cout << "Manufacturer: " << Make << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Year: " << Year << std::endl;
    }
};

class Car: private Vehicle{
    std::string trunk_size;
    
public:
    Car(){
        trunk_size = "";
    }
    Car(std::string mk, std::string col, int yr, std::string mdl, std::string ts)
    : Vehicle(mk, col, yr, mdl), trunk_size(ts){}
    
    void car_details(){
        print_details();
        std::cout << "Trunk size: " << trunk_size << std::endl;
        std::cout << "Model: " << Model << std::endl; // Model is protected and is accessible in 
                                                      // derived class
    }
};


int main(){
    Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
    // car.Year = 2000;     // this will give error as Year is private
    // car.Model = "Accord";   // this will give error as Model is protected

    car.car_details();
    //car.print_details();   // public functions of base class are inaccessible in main if Car inherits
                             // in private or protected mode



    return 0;
}
