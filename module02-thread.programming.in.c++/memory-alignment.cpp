#include <iostream>

using namespace std;

int main() {
    auto align = sizeof(void *);
    auto width = 4078;
    auto height = 5134;
    auto memoryAlign = width % align;
    auto memoryWidth = memoryAlign == 0 ? width : width + align - memoryAlign;
    double **q;
    q = new double *[height];
    q[0] = new double[height * memoryWidth];
    for (auto i = 1; i < height; i++)
        q[i] = q[i - 1] + memoryWidth;
    delete[]q[0];
    delete[]q;
    std::cerr << ((align == 8) ? "64-bit" : "32-bit") << std::endl;
}
