/*
 *   STL + template => Generic Programming
 *   Algorithm ((1) data type -> (2) vector/list/deque/set/map)
 *                  <template>: type independent ✔
 *                  <stl>: container independent ?
 *   Write/implement your algorithm once!
 *   Algorithm -> How to implement generic algorithm ?
 */

#include <vector>
#include <iostream>
#include <list>

/*
 *  Standard Template Library
 *    i. Container
 *       a. Linear Container:vector/list/deque/set
 *       b. Associative Container: (key->value) map/multimap
 *
 *   ii. Iterator
 *  iii. Algorithms
 */

int main() {
    std::list<int> numbers{4, 8, 15, 16};
    numbers.push_back(23);
    numbers.push_back(42);
    std::cerr << "size: " << numbers.size() << std::endl;
    std::cerr << "max_size: " << numbers.max_size() << std::endl;
    // std::cerr << "capacity: " << numbers.capacity() << std::endl;
    numbers.push_back(60);
    numbers.push_back(70);
    numbers.push_back(80);
    // numbers.reserve(1000000);
    std::cerr << "size: " << numbers.size() << std::endl;
    std::cerr << "max_size: " << numbers.max_size() << std::endl;
    // std::cerr << "capacity: " << numbers.capacity() << std::endl;
    // numbers.shrink_to_fit();
    std::cerr << "size: " << numbers.size() << std::endl;
    // std::cerr << "capacity: " << numbers.capacity() << std::endl;
    for (auto number : numbers)
        std::cout << number << " " ;
    std::cout << std::endl;
    numbers.resize(16);
    for (auto number : numbers)
        std::cout << number << " " ;
    std::cout << std::endl;
    return 0;
}