/*
 * Your task is to write a function left_rotate. Your function signature would be:
 * void left_rotate(int arr[], int size);
 * The input array arr[] will contain the values of type int. Your task is to rotate the values of an array
 * to the left.
 * Sample input: left_rotate({1, 2, 3, 4, 5}, 5)
 * Sample output: {2, 3, 4, 5, 1}
*/

#include <iostream>

void left_rotate(int arr[], int size){
    int temp = arr[0];
    for(int i = 1; i < size; ++i)
        arr[i - 1] = arr[i];
    arr[size - 1] = temp;
}

void print(int arr[], int size){
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


int main(){
    int arr[] {1, 2, 3, 4, 5};
    int size = std::size(arr);
    
    std::cout << "Array before rotate: ";
    print(arr, size);
    left_rotate(arr, size);
    std::cout << "Array after rotate: ";
    print(arr, size);

    return 0;
}
