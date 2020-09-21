#include <iostream>
#include <vector>

int main() {
    for (auto i : {4, 8, 15, 16, 23, 42}) { // for-each
        std::cout << i << std::endl;
    }
    std::vector<int> numbers{4, 8, 15, 16, 23, 42};
    for (auto number : numbers) { // for-each: read-only
        number++; // stack
        std::cout << number << std::endl;
    }
    for (auto& number : numbers) { // for-each: read-write
        number++;
        std::cout << number << std::endl;
    }
    for (auto pos = numbers.begin();
         pos != numbers.end();
         ++pos
    ){
        auto& number = *pos;
        number++;
        std::cout << number << std::endl;
    }
    auto sum = 0;
    for (const auto& number : numbers) sum += number;
    std::cout << "sum= " << sum << std::endl;
    int array[]{4, 8, 15, 16, 23, 42};
    sum = 0;
    for (const auto& number : array) sum += number;
    std::cout << "sum= " << sum << std::endl;

}

