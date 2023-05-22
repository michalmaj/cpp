/*
 * When a derived class inherits from a base class, it may choose to change soe of the inherited
 * functionality. This is called function overriding, since the derived class s overriding the functionality
 * of the base class.
 * Note: Overriding a function in a derived class hides all the overloads of the same function from the base
 * class.
*/
#include <iostream>

class Employee{
protected:
    std::string name;
    int ID;
    int reportsTo;
    
public:
    Employee(std::string name, int ID, int boss): name(name), ID(ID), reportsTo(boss){}
    std::string getName() {return name;}
    int getID() {return ID;}
    int getBoss() {return reportsTo;}
    
    void display(){
        std::cout << ID << " " << name << " reports to " << reportsTo << std::endl;
    }
    
    void display(std::string salutation){
        std::cout << salutation << " ";
        display();
    }
};

class Manager: public Employee{
protected:
    std::string teamName;
    
public:
    Manager(std::string name, int ID, int boss, std::string teamName)
    : Employee(name, ID, boss), teamName(teamName){}
    
    void display(){
        Employee::display();
        std::cout << " heads the team " << teamName << std::endl;
    }
};

int main(){
  Employee worker("John Smith", 10, 2);
  Manager ceo("Jack Hobbs", 0, 0, "Eats R Us");
  Manager cto("Elizabeth Shaw", 2, 0, "IT");
  worker.display("Mr");
  ceo.display();
  cto.display();
  //ceo.display("Mr")

    return 0;
}
