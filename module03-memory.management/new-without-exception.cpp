#include <iostream>

// C: malloc() -> NULL
int main() {
    const std::nothrow_t t;
    for (auto i = 0; i < 999999999; ++i) {
        int *p = new(t) int[9999999999];
        if (p == nullptr) {
            std::cerr << "Cannot allocate memory!" << std::endl;
            break;
        }
        std::cerr << "Memory allocated: " << std::ios::hex << p << std::endl;
    }
    return 0;
}