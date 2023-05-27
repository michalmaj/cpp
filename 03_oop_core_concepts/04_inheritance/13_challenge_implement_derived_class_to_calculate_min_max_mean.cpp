/*
 * In this exercise, you have to implement a derived class that will calculate the min, max and the mean of
 * the data set given in the dynamic array.
 * In this challenge, you are given a class called DynamicArray which implements a dynamic array of integers
 * that can grow in size.
 * This class has the following functions:
 *  - void append(int value): Adds a new value at the end of the array.
 *  - int get(int index): Returns the value at the given index.
 *  - int length(): Returns the current size of the array.
 *  - void resize(): Resizes the array when the maximum capacity is reached. The growth factor is two, 
 *    therefore, it will each time double the capacity of the array.
 * Your task is to write a derived class called DynamicArrayWithStats which will implement the following
 * functions:
 *  - int max(): Returns the maximum element in the dynamic array.
 *  - int min(): Returns the minimum element present in the dynamic array.
 *  - int mean(): Finds the mean value from the elements in the array and returns it.
*/

#include <iostream>
#include <cassert>


class DynamicArray {

    int *array;
    int capacity = 2;
    int size;

public:
    DynamicArray() {
        array = new int[capacity];
        size = 0;
    }

    void append(int element) {
        insertAt(element, size);
    }

    int length() {
        return size;
    }

    int get(int pos) {
        return array[pos];
    }

    ~DynamicArray() {
        delete[] array;
    }

private:
    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= size);
        if(size == capacity) {
            resize();
        }
        for(int i = size; i > pos; i--) {
            array[i] = array[i-1];
        }
        size++;
        array[pos] = element;
    }

    void resize() {
        capacity *= 2;
        int *temp = new int[capacity];
        std::copy(array, array + size, temp);
        delete [] array;
        array = temp;
    }

};

class DynamicArrayWithStats: public DynamicArray{

public:
    int max(){
        int result = get(0);
        for(int i{1}; i < length(); ++i){
            if(get(i) > result)
                result = get(i);
        } 
        return result;
    }
    
    int min(){
        int result = get(0);
        for(int i{1}; i < length(); ++i){
            if(get(i) < result)
                result = get(i);
        }
        return result;
    }
    
    int mean(){
        int sum = get(0);
        for(int i{1}; i < length(); ++i)
            sum += get(i);
        return (sum / length());
    }
};

int main() {
    DynamicArrayWithStats arr = DynamicArrayWithStats();
    arr.append(2);
    arr.append(6);
    arr.append(4);
    arr.append(1);
    arr.append(3);

    std::cout << "Array: ";
    for(int i = 0; i < arr.length(); i++){
        std::cout << arr.get(i) << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Max: " << arr.max() << std::endl;
    std::cout << "Min: " << arr.min() << std::endl;
    std::cout << "Mean: " << arr.mean() << std::endl;
    
    return 0;
}
