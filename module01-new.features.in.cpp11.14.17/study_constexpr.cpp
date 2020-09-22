#include <iostream>

constexpr auto square(const int x) { return x * x; }

constexpr auto cube(const int x) {
    return x * square(x);
}

constexpr auto fun(int x) {
    if (x == 1) return 1;
    return 1 + fun(x - 1);
}

float arr1[]{1, 2, 3, 4, 5, 6};
float arr2[6]{1, 2, 3, 4, 5, 6};
float arr3[6];
float arr4[fun(8)]; // data
float *arr5;
int main() {
    auto i = 42;
    arr5 = new float[i]; // heap
    std::cout << sizeof(arr1) / sizeof(float) << std::endl;
    std::cout << sizeof(arr2) / sizeof(float) << std::endl;
    std::cout << sizeof(arr3) / sizeof(float) << std::endl;
    std::cout << sizeof(arr4) / sizeof(float) << std::endl;
}

