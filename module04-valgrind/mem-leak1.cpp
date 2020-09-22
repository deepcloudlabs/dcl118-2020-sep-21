#include <iostream>

using namespace std;


int main(){
    // new -> delete
    // new[] -> delete[]
    int *p= new int(42);
    delete p;
    return 0;
}
