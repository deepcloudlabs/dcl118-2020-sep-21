#include <iostream>

void fun() {
    int x = 3; // x: l-value, 3: rvalue
    int &y = x;
    //int &z = 2; // ERROR!
    const int &u = 42;
}

int gun() { return 42; }

int & sun() {
    static int i = 108;
    i++;
    return i;
}
// variable: r-value, l-value
/*
int run(int i){ //i -> l-value: run(x), r-value: run(42)

}
 */
int run(int& i){ //i -> l-value: run(x)    std::cout << "run(int& i)" << std::endl;

    std::cout << "run(int& i)" << std::endl;
}
int run(int&& i){ //i -> r-value: run(42)
    std::cout << "run(int&& i)" << std::endl;
}
int mun(int *p){
    *p;
}
int main() {
    // gun() = 108; // ERROR: gun() is r-value
    sun() = 1024; // sun() is l-value
    int x = 108;
    run(42); // 42 -> r-value
    run(x); // x -> l-value
    mun(&x);
}
