/*
 * Your task is to write a function sort_elements. Your function signature would be:
 * int sort_elements(int arr[], int size);
 * The input array arr[] will contain the values of type int. Your task is to sort the elements of an array
 * in descending order.
 * Sample input: sort_elements ({10, 67, 98, 31}, 4 );
 * Sample output: {98, 67, 31, 10}
*/

#include <iostream>

void sort_elements(int arr[], int size){
    // Iterate for every item in an array
    for(int i = 0; i < size; ++i){
        int max = arr[i]; // Set max value as item at index i
        // Inner loop to iterate throughout array from + 1 to the end
        for(int j = i + 1; j < size; ++j){
            // If we found bigger value than max, put them on index i
            if(max < arr[j]){
                int temp = max; // Set temp variable to store previous max value
                max = arr[j]; // Change to max value to actual max
                
                // Swap max value to the beginning
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main(){
    int arr[]{10, 67, 98, 31};
    int size = std::size(arr);
    
    std::cout << "Array before sort: ";
    print(arr, size);
    
    sort_elements(arr, size);
    
    std::cout << "Array after sort: ";
    print(arr, size);

    return 0;
}
