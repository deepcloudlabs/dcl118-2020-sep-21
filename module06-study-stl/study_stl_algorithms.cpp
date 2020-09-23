#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

int main(){
    int numbers[] {11, 22, 33, 44, 55, 66, 77, 88};
    auto ptr = std::find(numbers+0,numbers+8,66);
    if (ptr == (numbers+8))
        std::cout << "Cannot find 66" << std::endl;
    else
        std::cout << "Found 66 at offset " << (ptr-numbers) << std::endl;
    std::vector<int> v{11, 22, 33, 44, 55, 66, 77, 88};
    auto p = std::find(v.begin(), v.end(), 99);
    if (p == v.end())
        std::cout << "Cannot find 99" << std::endl;
    std::vector<int> w(8),u;
    /*
    std::fill_n(w.begin(),8,10);
    std::fill(w.begin(),w.end(),42);
    std::copy(w.begin(),w.end(),u.begin());
    int src1[]{4,8,15,15,23,42};
    int src2[]{15,37,23,47};
    int destination[20];
    std::merge(src1+0,src1+6, src2+0, src2+4,destination+0);
     */
    std::vector<int> t{1,2,3,4};
    auto factorial = std::accumulate(t.begin(),t.end(), int(1), std::multiplies<int>() );
    std::cout << "factorial = " << factorial << std::endl;
    // auto sum = std::accumulate(t.begin(),t.end(), int(0), std::plus<int>() );
    auto sum = std::accumulate(t.begin(),t.end(), int() );
    std::cout << "sum = " << sum << std::endl;

}