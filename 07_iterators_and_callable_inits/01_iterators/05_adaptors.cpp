/*
 * Stream iterator adaptors can use stream as a data source or data sink. C++ offers two functions to create
 * istream iterators and two to create ostream iterators. The created istream iterators behave like input
 * iterators, the ostream iterators like insert iterators.
 *
 *  Function                                    Description
 *  std::istream_iterator<T>                    Creates an end-of-stream iterator.
 *  std::istream_iterator<T>(istream)           Creates an istream iterator for istream.
 *  std::ostream_iterator<T>(ostream)           Creates an ostream iterator for ostream.
 *  std::ostream_iterator<T>(ostream, delim)    Creates an ostream iterator for ostream with the delimiter.
 *
 * Example
 * Thanks to the stream iterator adapter we can directly read from or write to a stream.
 * The following program reads in an endless loop natural numbers from std::cin and pushes then onto the
 * vector myIntVet. If the input is not a natural number, an error in the input stream will occur. All
 * numbers in myIntVec are copied to std::cout, separated by :. Now we can see the result on the console.
*/
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>


int main(){
    std::vector<int> myIntVec;
    std::istream_iterator<int> myIntStreamReader(std::cin);
    std::istream_iterator<int> myEndIterator;
    
    // Possible input: 1 2 3 4 z
    while(myIntStreamReader != myEndIterator){
        myIntVec.push_back(*myIntStreamReader);
        ++myIntStreamReader;
    }
    
    std::copy(myIntVec.begin(), myIntVec.end(), std::ostream_iterator<int>(std::cout, ":"));


    return 0;
}
