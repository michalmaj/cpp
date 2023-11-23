// Function Template Argument Deduction by Value

template <typename T>
void funcValue(T param){}

int main(){

    int x = 2023;
    const int cx = x;
    const int& rx = x;

    funcValue(x);
    funcValue(cx);
    funcValue(rx);
}