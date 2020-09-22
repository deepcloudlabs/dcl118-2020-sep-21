#include <iostream>

using namespace std;

struct s { // declaration
    int i;
    long long j;
    long long m;
    int k;
};
s x; // allocation => Data

int main() {
    s y1; // allocation => Stack
    s y2; // allocation => Stack
    s *p = new s; // allocations:
    // 1. p: pointer => Stack
    // 2. new: object => Heap
    cout << "size of int is " << sizeof(int) << endl;
    cout << "size of long long is " << sizeof(long long) << endl;
    cout << "size of s is " << sizeof(s) << endl;
    return 0;
}