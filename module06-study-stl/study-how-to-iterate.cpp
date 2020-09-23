#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers{4, 8, 15, 16, 23, 42};
    std::cout << "read-write linear" << std::endl;
    for (auto p = numbers.begin(); // read-write
         p != numbers.end();
         ++p) {
        std::cout << *p << std::endl;
    }
    std::cout << "read-only linear" << std::endl;
    for (auto p = numbers.cbegin(); // read-only
         p != numbers.cend();
         ++p) {
        std::cout << *p << std::endl;
    }
    std::cout << "read-write reverse order" << std::endl;
    for (auto p = numbers.rbegin(); // read-write
         p != numbers.rend();
         ++p) {
        std::cout << *p << std::endl;
    }
    std::cout << "read-only reverse order" << std::endl;
    for (auto p = numbers.crbegin(); // read-only
         p != numbers.crend();
         ++p) {
        std::cout << *p << std::endl;
    }
    //read-only for-each
    for (const auto &number : numbers) { // since c++11: for-each
        std::cout << number << std::endl;
    }
    //read-write for-each
    for (auto &number : numbers) { // since c++11: for-each
        std::cout << number << std::endl;
    }
}