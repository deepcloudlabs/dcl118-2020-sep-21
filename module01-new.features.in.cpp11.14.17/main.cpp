#include <iostream>

void fun(int x){}
void fun(char* p){}

int main() {
    fun(0); // (int) -> fun(int)
    fun(static_cast<char*>(0L)); // fun(char*)
    fun(nullptr); // fun(char*), since c++11
    return 0;
}
