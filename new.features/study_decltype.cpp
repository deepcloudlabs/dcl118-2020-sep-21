#include <vector>
#include <iostream>

float x;
int y;
decltype(x * y) q; // float
decltype(&y) p; // int*
struct Person {
    double i;

    double fun(short) { return 3.14; }
};

int main() {
    Person p;
    decltype(p) z; // Person
    std::vector<decltype(p.i)> v;
    auto fun = [&]() -> decltype(z) {
        return Person();
    };
    auto j = 42.3;
    auto &k = j;
    const int& m = j;
    decltype(m) i1 = j;
    decltype(j) i2;
    decltype(k+1) i3;
    std::cout << "type of i1 " << typeid(i1).name() << std::endl;
    std::cout << "type of i2 " << typeid(i2).name() << std::endl;
    std::cout << "type of i3 " << typeid(i3).name() << std::endl;
    std::cout << "type of p " << typeid(p).name() << std::endl;
    std::cout << "type of q " << typeid(q).name() << std::endl;

}

