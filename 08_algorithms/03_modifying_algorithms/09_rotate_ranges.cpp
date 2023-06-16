/*
 * We can rotate our data such that every element now lies at a different index, which is decided by the
 * rotation offset.
 * std::rotate and std::rotate_copy rotate their elements.
 *  std::rotate - rotates the elements in such a way that middle becomes the new first element.
 *  std::rotate_copy - rotates the elements in such a way that middle becomes the new first element. Copies
 *                     the result to result.
 * Both algorithms need forward iterators. The returned iterator is an end iterator for the copied range.
*/
#include <algorithm>
#include <iostream>
#include <string>

int main(){
    std::string str{"123456789"};   
    for(auto it = str.begin(); it != str.end(); ++it){
        std::rotate(str.begin(), it, str.end());
        std::cout << str << std::endl;
    }


    return 0;
}
