/*
 * We can access the elements stored in an array by writting the array name, which is followed by its
 * index in the square brackets.
 * The first element of an array is stored at index 0, and the last element is stored at index size - 1.
 *
 * If we try to access an index that is greater than the size of an array, the compiler won't generatr
 * an error, but may give you an unexpected output.
*/

#include <iostream>

int main(){
    // The index value of this array will range from 0 to 4.
    int arr[]{100, 101, 102, 103, 104};
    
    // Access to fifth element (will be at index 4)
    std::cout << arr[4] << "\n";
    
    // Accessing each and every element in an array and then printing its value is a repetetive task.
    // We can print all elements of an array using the for loop.
    for(int i = 0; i < 5; ++i){
        // Accessing element at index i
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    
    // We can also use Range-based for loop
    // It executes a for loop over a range.
    // Used as a more readable equivalent to the traditional for loop operating over a range of values, 
    // such as all elements in a container. 
    // Note: For array it works only if an array is declared is the same scope!
    for(int element : arr)
        std::cout << element << " ";
    std::cout << "\n";
    


    return 0;
}
