#include <iostream>
#include <range/v3/algorithm/count.hpp> // specific includes
#include <vector>
#include <array>

using std::cout;

int
main()
{
    std::vector<int> v{6, 2, 3, 4, 5, 6};
    // note the count return is a numeric type
    // like int or long -- auto below make sure
    // it matches the implementation
    auto c = ranges::count(v, 6);
    cout << "vector:   " << c << '\n';

    std::array<int, 6> a{6, 2, 3, 4, 5, 6};
    c = ranges::count(a, 6);
    cout << "array:    " << c << '\n';
}