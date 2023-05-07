/*
 * In a static array, a fixed amount of memory is allocated to the array during the compile time. Therefore,
 * we cannot allocate more memory to the arrays during program execution.
 * Dynamic arrays can grow or shrike during the program execution. General syntax for declaring arrays is
 * given below:
 * DataType* ArrayName = new DataType[size];
 * The basic syntax for deallocating a dynamic array is given below:
 * delete[] ArrayName;
*/
#include <iostream>

// Function for printing an array
void print(int arr[], int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

// Initialize or fill array
void initialize(int* arr, int size, int start = 0){
    for(int i = start; i < size; ++i)
        arr[i] = i + 1;
}

// Resize array
int* resize(int* arr, int size, int new_size){
    // Create new array with new size
    int* resized_array = new int[new_size];

    // Check if the new size isn't less than actual
    int sz = size;
    if(sz > new_size)
        sz = new_size;

    // Copy elements from old array
    for(int i = 0; i < sz; ++i)
        resized_array[i] = arr[i];

    // Delete old array
    delete[] arr;

    // Old pointer are going to point new piece of memory
    arr = resized_array;

    // Array created inside this function will be nullpointer
    resized_array = nullptr;

    // Return pointer to resized array
    return arr;
}


int main(){
    // Initialize variable size
    int size = 5;

    // Create Array
    int* arr = new int[size];

    // Initialize dynamic array
    initialize(arr, size);

    // Print array
    print(arr, size);

    int new_size = 10;

    // Resize array to new_size
    arr = resize(arr, size, new_size);

    // Initialize unused values (won't change is new_size < size)
    initialize(arr, new_size, size);

    // Print new
    print(arr, new_size);

    // Clean up before end of program.
    delete[] arr;

    return 0;
}
