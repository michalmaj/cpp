/*
 * We have seen thet Vehicle class attributes are shared by the other two classes (Car and Ship).
 * We can consider the Vehicle class as base class a it has common attibutes.
 * Car and Ships are considered as derived classes as they're inheriting properties from Vehicle class.
 * There are three modes of class inheritance: public, private and protected. The basic syntax for 
 * inheritance looks like ths:
 *  class derivedClass : modeOfInheritance baseClassName 
 * protected and public data members are accessible to derived classes
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

class Cars: public Vehicle{
    std::string trunk_size;
    
public:
    Cars(){
        trunk_size = "";
    }
    Cars(std::string mk, std::string col, int yr, std::string mdl, std::string ts)
    : Vehicle(mk, col, yr, mdl){
        trunk_size = ts;
    }
    void car_details(){
        print_details();
        std::cout << "Trunk size: " << trunk_size << std::endl;
    }
};

class Ships: public Vehicle{
    int Number_of_Anchors;
    
public:
    Ships(){
        Number_of_Anchors = 0;
    }
    Ships(std::string mk, std::string col, int yr, std::string mdl, int na)
    : Vehicle(mk, col, yr, mdl){
        Number_of_Anchors = na;
    }
    void Ship_details(){
        print_details();
        std::cout << "Number of Anchors: " << Number_of_Anchors << std::endl;
    }
};


int main(){
    Cars car("Chevrolet", "Black", 2010, "Camaro", "9.1 cubic feet");
    car.car_details();

    std::cout << std::endl;

    Ships ship("Harland and Wolff, Belfast", "Black and whilte", 1912, "RMS Titanic", 3);
    ship.Ship_details();


    return 0;
}
