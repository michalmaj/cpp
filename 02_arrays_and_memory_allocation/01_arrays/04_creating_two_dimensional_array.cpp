/*
 * A two-dmensonal array is an array of arrays.
 * Two-dimensional arrays represent a matrix. We can access the element in a two-dmensional array by the
 * row and column index. Both the row and column index start at 0.
 * Syntax: DataType ArrayName[RowSize][ColumnSize];
 *
 * If we initialize an array with elemnts fewer than its total size, t automatically initialize the 
 * remaining elements with their default values.
 *
 * When initializing a 2-D array, specifying the frst dimension (rows) is optional. The compiler will
 * infer the number of rows from the statement.
 * Note: If we aren't initializing a 2-D array, all of its dimensions must be specified.
*/

#include <iostream>

int main(){
    int arr[][3] = {
        {100, 134, 234},
        {34, 189, 221},
        {109, 139, 56}
    };

    return 0;
}
