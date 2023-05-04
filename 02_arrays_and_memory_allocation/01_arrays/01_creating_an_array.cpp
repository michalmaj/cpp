/*
 * An array is a collection of elements of the same data type a the single name.
 * Array declaration: DataTyepe ArrayName [ArraySize];
*/

#include <iostream>

// A helper function to print content of the array
void print_arr(int arr[], int len){
    for(int i = 0; i < len; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main(){
    // Approach 1 - we can assign a value to an array by element by accessing its index.
    int arr1[5];
    
    arr1[0] = 100;
    arr1[1] = 101;
    arr1[2] = 102;
    arr1[3] = 103;
    arr1[4] = 104;
    
    print_arr(arr1, 5);
    
    // Approach 2 - we can assign a value to the array elements in the declaration step.
    int arr2[] = {100, 101, 102, 103, 104}; // Compler will deduce size, no need to put any value in []
    
    print_arr(arr2, 5);
    
    // Extras - we can initialize an array with fewer elements than its total size
    int arr3[5]{100, 101}; // In modern C++ we can initialize values without = sign
    
    // Uninitialized values will be 0
    print_arr(arr3, 5);

    return 0;
}
