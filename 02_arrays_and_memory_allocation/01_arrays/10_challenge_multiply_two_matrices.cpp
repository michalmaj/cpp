/*
 * Your task is to write a function multiplication. Your function signature would be:
 * void multiplication(int arr1[][2], int row1, int col1, int arr[][2], int row2, int col2, int result[][2])
 * The function multiplication will take three 2D arrays of type nt and their row and column index in its
 * input parameters. In the function body, we will multiply the two matrices arr1[][2] to arr2[][2], store
 * our result in result[][2], and return it in the output.
 * Note: We can only multiply the two matrces if the number of columns of the first matrix equals the
 * numbers of rows of the second matrix. f this condition is not fulfilled, your program should set all the
 * values of result[][2] matrix to -1;
*/

#include <iostream>

void multiplication(int arr1[][2], int row1, int col1, int arr2[][2], int row2, int col2, int result[][2]){
    if(col1 != row2){
        for(int i = 0; i < row1; ++i){
            for(int j = 0; j < col2; ++j)
                result[i][j] = -1;
        }
        return;
    }

    for(int r1 = 0; r1 < row1; ++r1){
        for(int c2 = 0; c2 < col2; ++c2){
            for(int c1 = 0; c1 < col1; ++c1){
                    result[r1][c2] += arr1[r1][c1] * arr2[c1][c2];
            }
        }
    }
}


int main(){

    int arr1[2][2] = {{1,2} , {5,7}};
    int arr2[2][2] = {{10,20} , {-30,70}};
    int result[2][2]{0};

    multiplication(arr1, 2, 2, arr2, 2, 2, result);

    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j)
            std::cout << result[i][j] << " ";
        std::cout << std::endl;
    }


    return 0;
}
