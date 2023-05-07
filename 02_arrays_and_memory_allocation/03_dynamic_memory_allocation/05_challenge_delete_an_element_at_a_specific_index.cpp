/*
 * Your task is to writ a function delete_element. In its input parameters, the function will take:
 *  - Pointer arr of type int by reference. Pointer arr is pointing to dynamically allocated array.
 *  - Variables size and index of type int.
 * void delete_element(int* &arr, int size, int index)
 * Your task is to delete the element in an array at the given index.
 *
 * Note: By default, pointers are passed by value. This means that if we point the pointer to a different
 * memory location inside the function, it still points to the previous memory location outside the
 * function. Here, we are passing ponters by reference, so if we change the address stored in a pointer
 * inside the function, it is also changed outside the function.
*/

#include <iostream>

// Delete element at give index
void delete_element(int* &arr, int& size, int index){
    // Create an iterator
    int it = 0;
    // Create new temporary array with size one less
    int* new_arr = new int[size - 1];
    
    // Copy values over passed array, but skip passed index
    for(int i = 0; i < size; ++i){
        if(i == index)
            continue;
        new_arr[it++] = arr[i];
    }
    
    // Delete old array
    delete[] arr;
    
    // Give pointer of newly created array to old array
    arr = new_arr;
    
    // Set new_arr to nullptr
    new_arr = nullptr;
    
    // We can also change oryginal value of variable size
    size--;
}

void print(int* arr, int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main(){
    int size = 4;
    int* arr = new int[size]{10, 67, 98, 31};
    
    print(arr, size);

    delete_element (arr, size , 2 );
    
    print(arr, size);

    return 0;
}
