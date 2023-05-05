/*
 * Your task is to rite a function add_diagonal. YOur functon signature would be:
 * int add_diagonal(int arr[3][3], int row, int col);
 * The input array arr[][] will contain the values of type int. Your task is to add the elements
 * in the main diagonal of the matrix.
*/

#include <iostream>

int add_diagonal(int arr[3][3], int row, int col){
    // Declare variable to store sum of diagonal
    int sum = 0;
    
    // Start adding from index [0][0]
    int i = 0;
    int j = 0;
    
    while(i < row && j < col){
        sum += arr[i][j];
        // Next value will be [1][1], then [2][2] and so on
        i++;
        j++;
    }
    return sum;
}

int main(){
    const int row = 3;
    const int col = 3;
    
    int arr[row][col] = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };
    
    std::cout << "Sum of diagonal: " << add_diagonal(arr, row, col) << "\n";

    return 0;
}
