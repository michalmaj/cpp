// Template Default Arguments
#include <functional>
#include <iostream>
#include <string>

class Account {
public:
    explicit Account(double b) : balance(b) {}

    double getBalance() const { return balance; }

private:
    double balance;
};

// This function is parametrized by a second template parameter, which defines the comparison criterion. The default
// comparison is the predefined function object std::less. A function object is a class for which the call operator
// (operator()) is overloaded. This means that instances of function object behave similarly as a function.
template <typename T, typename Pred=std::less<T>>
bool isSmaller(T fir, T sec, Pred pred=Pred()){
    return pred(fir, sec);
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "isSmaller(3, 4): " << isSmaller(3, 4) << "\n";
    std::cout << "isSmaller(2.14, 3.14): " << isSmaller(2.14, 3.14) << "\n";
    std::cout << R"(isSmaller(std::string("abc"), std::string("def"): )"<<
        isSmaller(std::string("abc"), std::string("def")) << "\n";

    bool resAcc = isSmaller(Account(100.0), Account(200.0),
                            [](const Account& a1, const Account& a2){
                                return a1.getBalance() < a2.getBalance();
    });
    std::cout << "isSmaller(Account(100.0), Account(200.0): " << resAcc << "\n";

    bool acc= isSmaller(std::string("3.14"),std::string("2.14"),
                        [](const std::string& fir, const std::string& sec){
                            return std::stod(fir) < std::stod(sec);
    });
    std::cout << R"(isSmaller(std::string("3.14"),std::string("2.14")): )" << acc << std::endl;

    return 0;
}