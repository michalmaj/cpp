/*
 * Non-modyfing a;gorithms are algorithms for searching and counting elemets. However, we can also check
 * properties on ranges, compare ranges or search for ranges within ranges.
 * 
 * Search elements.
 * We can search for elements in three different ways.
 *  1. Return an element in a range.
 *  2. Return the first element of a range in a range.
 *  3. Return identical, adjacent elements in a range.
 * The algorithms require input or forward iterators as arguments and return an iterator on the element when
 * successfully found. If the search is not successful, they return an end iterator.
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <list>

bool isVowel(char c){
    std::string myVowels{"aeiouäöü"};
    std::set<char> vowels(myVowels.begin(), myVowels.end());
    return (vowels.find(c) != vowels.end());
}

int main(){
    std::list<char> myCha{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    int cha[]= {'A', 'B', 'C'};

    
    auto it1 = std::find(myCha.begin(), myCha.end(), 'g');
    std::cout << "*it1: " << *it1 << " at index: " << (std::distance(myCha.begin(), it1)) << std::endl;
    
    auto it2 = std::find_if(myCha.begin(), myCha.end(), isVowel);
    std::cout << "*it2: " << *it2 << " at index: " << std::distance(myCha.begin(), it2) << std::endl;
    
    // We can reuse one of above iterators, or we can create a new one
    it1 = std::find_if_not(myCha.begin(), myCha.end(), isVowel);
    std::cout << "*it1: " << *it1 << " at index: " << std::distance(myCha.begin(), it1) << std::endl;
    
    // Here we can also reuse above iterators, but let's create a new one
    //auto iter = std::find_first_of(myCha.begin(), myCha.end(), cha, cha+3); // Old version
    auto iter = std::find_first_of(myCha.begin(), myCha.end(), std::begin(cha), std::end(cha)); // New one
    
    if(iter == myCha.end()) std::cout << "None of A, B, or C inside myCha\n";
    
    // Treat character as upper (only in this function - copy is made)
    iter = std::find_first_of(myCha.begin(), myCha.end(), std::begin(cha), std::end(cha),
                              [](char a, char b){return toupper(a) == toupper(b);});
    if(iter != myCha.end())
        std::cout << "*iter: " << *iter << " at index: " << std::distance(myCha.begin(), iter) << std::endl;
    
    auto iter2 = std::adjacent_find(myCha.begin(), myCha.end());
    if (iter2 == myCha.end()) std::cout << "No same adjacent chars." << std::endl;
    
    iter2 = std::adjacent_find(myCha.begin(), myCha.end(),
                              [](char a, char b){return isVowel(a) == isVowel(b);});
    if(iter2 != myCha.end())
        std::cout << "*iter2: " << *iter2 << " at index: " << std::distance(myCha.begin(), iter2) << "\n";
     
    return 0;
}
