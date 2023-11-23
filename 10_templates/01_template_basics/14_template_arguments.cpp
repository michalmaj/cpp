// Function Template Argument Deduction by Reference

template <typename T>
void func(T& param){}

template <typename T>
void constFunc(const T& param) {}

int main(){

    int x = 2023;
    const int cx = x;
    const int& rx = x;

    func(x);
    func(cx);
    func(rx);

    constFunc(x);
    constFunc(cx);
    constFunc(rx);

    return 0;
}