/*
 * std::prev_permutation and std::next_permutation return the previous smaller or next bigger permutation
 * of the newly ordered range. If a smaller or bigger permutation is not available, the agorithm return 
 * false. Both algorithms need bidirectional iterators. PEr default the predefined sorting criterion 
 * std::less is used. If we use our sorting criterion, it has to obey the strict weak ordering. If not, the
 * program is undefined.
 * Note: range must be sorted - ascending for std::next_permutation, descending for std::prev_permutaon.
*/
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myInts{1, 2, 3};
    
    std::cout << "All 3! forward permutaions" << std::endl;
    do{
        std::cout << myInts << std::endl;
    }while(std::next_permutation(myInts.begin(), myInts.end()));
    
    std::cout << std::endl;
    
    std::reverse(myInts.begin(), myInts.end());
    std::cout << "All 3! backward permutations" << std::endl;
    do{
        std::cout << myInts << std::endl;
    }while(std::prev_permutation(myInts.begin(), myInts.end()));

    return 0;
}
