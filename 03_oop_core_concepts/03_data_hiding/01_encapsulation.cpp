/*
 * Data hiding refers to the concept of hiding the inner structure of a class. An interface is provided
 * through which the outside world can interact with the class without knowing its internal details.
 * Our goal is to make the interaction between different classes as simple as possible. This can only be
 * achieved if the interfaces of the classes are simple. One class does not need to know anything about the
 * underlying algorithms of another class. However, the two can still communicate.
 * Components of data hiding:
 * Data hiding can be divided nto two primary components:
 *  1. Encapsulation.
 *  2. Abstraction.
 *
 * Advantages of Encapsulation
 *  - Classes are easier to change and mantain.
 *  - We can specify which data member we want to keep hidden or accessible.
 *  - We decide which variables have read/write privileges (increases flexibility).
*/
#include <iostream>

class Movie{
    std::string title;
    int year;
    std::string genre;
    
public:
    Movie(){
        title = "";
        year = -1;
        genre = "";
    }
    
    Movie(std::string t, int y, std::string g){
        title = t;
        year = y;
        genre = g;
    }
    
    // Getters
    std::string getTitle() {return title;}
    int getYear() {return year;}
    std::string getGenre() {return genre;}
    
    // Setters
    void setTitle(std::string t){title = t;}
    void setYear(int y){year = y;}
    void setGenre(std::string g){genre = g;}
    
    // Methods
    void printDetails(){
        std::cout << "Title: " << title << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Genre: " << genre << std::endl;
    }
};

int main(){
    Movie m("The Lion King", 1994, "Adventure");
    m.printDetails();

    std::cout << "---" << std::endl;
    m.setTitle("Forrest Gump");
    std::cout << "New title: " << m.getTitle() << std::endl;

    return 0;
}
