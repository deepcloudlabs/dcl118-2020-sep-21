#include <vector>
#include <string>
#include <list>

auto fun(){ return 3;}
auto run(int){ return false; }

int main(){
    // auto z ; // ERROR
    auto x{42};
    auto y = fun();
    static auto vat = 0.18;
    auto p = &x;
    auto q = fun;
    int (*r)() = fun;
    fun();
    q();

    std::list<int> names;
    auto pos = names.begin();
    while(pos != names.end()){
        auto name = *pos;
        pos++;
    }
               // lambda expression
    auto gun = [](int x) -> bool { return true; };
    bool (*sun)(int) = [](int x) -> bool { return true; };
    sun = run;
}

