/*
 * We know a class HAS-A data members and member functions. Now, we want the data members, and member 
 * functions of the class are accessible from other classes. So, the capability of a class to derive
 * properties and characteristics from another class is called Inheritance. In inheritance, we have IS-A
 * relationship between classes e.g a car is a vahicle and a ship is a vahicle.
 *
 * Example:
 * Vehicle Class
 * In a Vehicle class, we have many data members like Make, Color, Year, and Model. A Vehicle HAS-A Model,
 * Year, Color, and Make. These attributes are also attributes of all Cars, Ships and Airplanes but every
 * type of vehicle has some attributes that are different from other types of vehicles.
 *
 * Car Class
 * The implementation of a Car class needs the same data members and member functions of Vehicle class but
 * we have to include them in the Car class. Cars do have a trunk and every trunk has a capacity to store
 * things upto some limits.   
 *
 * Ship Class
 * The implementation of a Ship class needs the same data members and member functions of Vehicle class but
 * we have to include them in the Ship class. Ships do have anchors and they vary in numbers.
 *
 * In the declare classes for different types of vehicles (Car and Shp), we have many repetitive attributes
 * which should be in one class and should be inherited in the derived classes.
*/
#include <iostream>

class Vehicle{
protected:
    std::string Make;
    std::string Color;
    int Year;
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
        std::cout << "Model: " << Model << std::endl;
    }
};

class Car{
    std::string Make;
    std::string Color;
    int Year;
    std::string Model;
    std::string trunk_size;
    
public:
    Car(){
        Make = "";
        Color = "";
        Year = 0;
        Model = "";
        trunk_size = "";
    }
    Car(std::string mk, std::string col, int yr, std::string mdl, std::string ts){
        Make = mk;
        Color = col;
        Year = yr;
        Model = mdl;
        trunk_size = ts;
    }
    void print_details(){
        std::cout << "Manufacturer: " << Make << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Year: " << Year << std::endl;
        std::cout << "Model: " << Model << std::endl;
        std::cout << "Trunk size: " << trunk_size << std::endl;
    }
};

class Ship{
    std::string Make;
    std::string Color;
    int Year;
    std::string Model;
    int Number_of_Anchors;
    
public:
    Ship(){
        Make = "";
        Color = "";
        Year = 0;
        Model = "";
        Number_of_Anchors = 0;
    }
    Ship(std::string mk, std::string col, int yr, std::string mdl, int na){
        Make = mk;
        Color = col;
        Year = yr;
        Model = mdl;
        Number_of_Anchors = na;
    }
    void print_details(){
        std::cout << "Manufacturer: " << Make << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Year: " << Year << std::endl;
        std::cout << "Model: " << Model << std::endl;
        std::cout << "Number of Anchors: " << Number_of_Anchors << std::endl;
    }
};

int main(){
    Vehicle v("Ford Australia", "Yellow", 2008, "Falcon");  
    v.print_details();
    std::cout << std::endl;
      
    Car car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
    car.print_details();
    std::cout << std::endl;
    
    Ship ship("Harland and Wolff, Belfast", "Black and whilte", 1912, "RMS Titanic", 3);
    ship.print_details();


    return 0;
}
