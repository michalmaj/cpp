/*
 * The reason for the constant access time of an unordered associative container is the hash function. The
 * hash function maps the key to its value (its hash value). A hash function is good if it produces as few
 * collisions as possible and equally distributes the keys onto the buckets. Because the execution of the 
 * hash function takes a constant amount of time, accessing the elements in the base case is also constant.
 *
 * The hash function:
 *  - is already defined for the buil-in types like boolean, natural numbers, and floating point numbers.
 *  - is available for std::string and std::wstring.
 *  - generates, for a C string, const char a shas value of the pointer address.
 *  - can be defined for user-defined data types.
 * For user-defined types, which are used as a key for an unordered associative container, we have to keep
 * two requirements in mind: They need a has function and an equality operator to be defined in order for 
 * them to be compared.
*/
#include <iostream>
#include <unordered_map>
#include <concepts> // -std=c++20

struct MyInt{
    MyInt(int v): val{v} {}
    bool operator==(const MyInt& other) const{
        return val == other.val;
    }
    
    int val;
};

std::ostream& operator<<(std::ostream& out, const MyInt& m){
    out << m.val;
    return out;
}

struct MyHash{
    size_t operator()(const MyInt& m)  const{
        std::hash<int> hashVal;
        return hashVal(m.val);
    }
};

template <typename T>
concept map_type = 
    std::same_as<T, std::unordered_map<typename T::key_type, typename T::mapped_type,
        typename T::hasher, typename T::key_equal, typename T::allocator_type>>;
        
template <map_type Container>
std::ostream& operator<<(std::ostream& out, const Container& c){
    size_t len = c.size();
    for(const auto& [k, v] : c){
        len--;
        if(len)
            out << "{" << k << "," << v << "}\n";
        else
            out << "{" << k << "," << v << "}";
    }
    return out;
}

int main(){
    std::unordered_map<MyInt, int, MyHash> myIntMap{
        {MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1}
    };
    std::cout << "myIntMap contains:\n" << myIntMap << std::endl;
    
    std::cout << "myIntMap[MyInt(-1)]: " << myIntMap[MyInt(-1)] << std::endl;

    return 0;
}
