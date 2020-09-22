#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 999999999; ++i) {
        try {
            int *p = new int[99999999999];
            cerr << "Memory allocated: " << std::ios::hex << p << std::endl;
        } catch (std::bad_alloc e) {
            std::cerr << "Cannot allocate memory: " << e.what() << std::endl;
            break;
        }
    }
    return 0;
}
