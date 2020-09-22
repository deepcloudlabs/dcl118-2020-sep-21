#include <iostream>

struct A { // 24-Byte ? 32-Byte ?
    int i; // 4
    // 4-byte
    long long k; // 8
    int j; // 4
    // 4-byte
    long long m; // 8
    int n; //4
    // 4-byte

    void fun() {
        this->i++;
    }

    void gun();
};

A a1; // data -> (i, j, k, m) : attribute

int main() {
    A a2; // stack
    std::cout << "sizeof(void*): " << sizeof(void*) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;
    std::cout << "sizeof(A): " << sizeof(A) << std::endl;
}