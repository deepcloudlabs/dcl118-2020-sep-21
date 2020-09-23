#include "city.h"
#include "country.h" 
#include "world-util.h" 

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <memory>

#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <memory>

#include <range/v3/core.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/view/view.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/algorithm/for_each.hpp>

using namespace std;
using namespace world;
using namespace ranges::v3;

std::map<int,std::shared_ptr<world::city>> cities;
std::map<std::string,std::shared_ptr<world::country>> countries;

int main(int argc, char* argv[]){
    create_world();
    auto is_asian = [](shared_ptr<country> &a_country) -> bool {
        return a_country->continent.compare("Asia") == 0;
    };
    const auto asian_countries=countries | view::values | view::filter(is_asian) | to_vector ;
    for (auto& a_country : asian_countries)
        cout << *a_country << endl;
    return 0;
}