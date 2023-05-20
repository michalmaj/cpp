/*
 * A destructor is the opposite of a constructor. It is called when the object of a class is no longer is
 * use. The object is destroyed and the memory it occuoied is now free for future use.
 * In this destructor, we can specify the addition operations which need to be performed when a class object
 * is deleted.
 * A class destructor can be created is a similar way to the constructor, except that the destructor is
 * preceded by the ~ keyword.
*/
#include <iostream>

class Collector{
    int* list;
    int size;
    int capacity;
    
public:
    // Default constructor
    Collector(){
        // We must define the default values for the data members
        list = nullptr;
        size = 0;
        capacity = 0;
    }
    
    // Parametrized  constructor
    Collector(int cap){
        // The arguments are used as values
        capacity = cap;
        size = 0;
        list = new int[capacity];
    }
    
    // Destructor
    ~Collector(){
        std::cout << "Deleting the object\n";
        delete[] list;
    }
    
    // Methods
    bool append(int v){
        if(size < capacity){
            list[size++] = v;
            return true;
        }
        return false;
    }
    
    void print(){
        for(int i{0}; i < size; ++i)
            std::cout << list[i] << " ";
        std::cout << std::endl;
    }
};


int main(){
    Collector c(10);
    for(int i{0}; i < 15; ++i)
        std::cout << std::boolalpha << c.append(i) << std::endl;

    c.print();

    return 0;
}
