/*
 * We can easily push std::shared_ptr onto an std::vector<std::shared_ptr<int>> with different deleters.
 * The special deleter will be stored in the control block.
*/
#include <iostream>
#include <memory>
#include <random>
#include <typeinfo>

// Deleter is the special deleter. The deleter is parametrized by the type T. It counts, alongside
// the static variable count, how often the call operator was used.
template <typename T>
class Deleter{
public:
    void operator()(T* ptr){
        ++Deleter::count;
        delete ptr;
    }
    
    // Deleter returns all the information with getInfo method.
    void getInfo(){
        std::string typeId{typeid(T).name()};
        size_t sz = Deleter::count * sizeof(T);
        std::cout << "Deleted " << Deleter::count << " objects of type: " << typeId << "\n";
        std::cout << "Freed size in bytes: " << sz << "\n";
        std::cout << std::endl;
    }
    
private:
    static int count;
};

template <typename T>
int Deleter<T>::count = 0;

typedef Deleter<int> IntDeleter;
typedef Deleter<double> DoubleDeleter;

// This functon creates between 1 to 1000 std::shared_ptr parametrized by the specal deleter intDeleter()
void createRandomNumbers(){
    std::random_device seed;
    
    std::mt19937 engine(seed());
    
    std::uniform_int_distribution<int> thousand(1, 1000);
    int randNumber = thousand(engine);
    for(int i{0}; i <= randNumber; ++i)
        std::shared_ptr<int>(new int(i), IntDeleter());
}

int main(){

    {
        std::shared_ptr<int> sp1(new int, IntDeleter());
        std::shared_ptr<int> sp2(new int, IntDeleter());
        auto intDeleter = std::get_deleter<IntDeleter>(sp1);
        intDeleter->getInfo();
        sp2.reset();
        intDeleter->getInfo();
    }
    
    createRandomNumbers();
    IntDeleter().getInfo();
    
    {
        std::unique_ptr<double, DoubleDeleter> up(new double, DoubleDeleter());
        std::unique_ptr<double, DoubleDeleter> up1(new double, DoubleDeleter());
        std::shared_ptr<double> sp(new double, DoubleDeleter());
        
        std::shared_ptr<double> sp4(std::move(up));
        std::shared_ptr<double> sp5 = std::move(up1);
        DoubleDeleter().getInfo();
    }
    
    DoubleDeleter().getInfo();

    return 0;
}
