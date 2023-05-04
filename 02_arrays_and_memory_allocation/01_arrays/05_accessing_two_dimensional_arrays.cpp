/*
 * To access elements in a two-dimensional array, we have to specify a row and column index.
 * Like in one-dimensional array, the index of row and columns starts at 0. For example, the first
 * element of a two-dimensional array is at index [0][0], the second element is stored at index [0][1],
 * and so on.
*/

#include <iostream>

int main(){
    // Initialize row and column variables.
    // Note both must be const
    const int row = 3;
    const int col = 3;
    
    // Initialize static 2D array
    int arr[row][col] = {
        {100, 134, 234},
        {34, 189, 221},
        {109, 139, 56}
    };

    // Print static 2D Array
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            // Access element at row index r and column index c
            std::cout << arr[r][c] << " ";
        }
        std::cout << "\n";
    }


    return 0;
}
