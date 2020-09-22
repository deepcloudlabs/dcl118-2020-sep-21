#include <iostream>

// C: malloc() -> NULL
int main(){
    for (auto i=0; i < 999999999; ++i){
        try{
            int *p = new int[9999999999];
            std::cerr << "Memory allocated: " << std::ios::hex << p << std::endl;
        } catch (std::bad_alloc& e) {
            std::cerr << "Cannot allocate memory: " << e.what() << std::endl;
            break;
        }
    }
    return 0;
}