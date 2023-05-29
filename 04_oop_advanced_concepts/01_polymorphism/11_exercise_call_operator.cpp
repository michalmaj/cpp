/*
 * Implement the functionality in the example we saw in the previous file with the help of a lamba function. 
#include <algorithm>
#include <iostream>
#include <vector>

class SumMe{
public:
    SumMe(): sum(0) {}
    void operator()(int x){
        sum += x;
    }
    int getSum() const{
        return sum;
    }
    
private:
    int sum;
};

int main(){
    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    SumMe sumMe = std::for_each(intVec.begin(), intVec.end(), SumMe());
    std::cout << "sumMe.getSum(): " << sumMe.getSum() << std::endl;

    return 0;
}
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(){
    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // First of all, the variable sum represents the state of the lambda function.
    // With C++14, the so-called initialization capture of lambda is supported. sum{0} declares and 
    // initializes a variable of type int which is only valid n the scope of the lambda function.
    int sum{0};
    // The lmabda function is used. Note that they are constant by default.
    // &sum stores the address of last updated value of sum.
    std::for_each(intVec.begin(), intVec.end(), [&sum](int x){sum += x;});
    std::cout << "sum: " << sum << std::endl;

    return 0;
}
