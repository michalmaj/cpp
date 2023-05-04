/*
 * To pass an array to a function, we just have to specify the array type, followed by an array name and
 * swuare brackets in the function parameters.
*/

#include <iostream>

int sum_arr(int numbers[], int size){
    int mySum = 0;
    for(int i = 0; i < size; ++i)
        mySum += numbers[i];
        
        
    return mySum;
}

int main(){
    int arr[]{12, 14, 9, 8, 22, 17, 6};
    
    // In modern C++ for that type of arrays we can calculate size using std::size(arr) function
    int size = std::size(arr);
    int result = sum_arr(arr, size);
    std::cout << "Sum: " << result << "\n";


    return 0;
}
