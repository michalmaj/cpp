/*
 * Your task is to write a function set_odd. In function parameters, we will pass:
 *  - Pointer arr, that will point to an array of type int.
 *  - The siez of an int array.
 * void set_odd(int* arr, int size)
 * Your task is to set the odd elements to -1.
*/

#include <iostream>

// Function for changing odd values to -1
void set_odd(int* arr, int size){
    for(int i = 0; i < size; ++i){
        if(arr[i] % 2 != 0)
            arr[i] = -1;
    }
}

// Function for printing an array
void print(int* arr, int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main(){
    int size = 4;
    int* arr = new int[size]{10, 67, 31, 98};
    
    std::cout << "arr before change: ";
    print(arr, size);
    
    set_odd(arr, size);
    
    std::cout << "arr after change: ";
    print(arr, size);
    
    
    
    delete[] arr;

    return 0;
}
