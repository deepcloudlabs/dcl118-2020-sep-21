#include "city.h"
#include "country.h" 
#include "world-util.h" 

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
    auto country_name_mapper = [](shared_ptr<country> &a_country) -> string {
        return a_country->name ;
    };

    const auto countries_names= countries | view::values | view::transform(country_name_mapper) | to_vector ;

    for (auto& country_name : countries_names)
        cout << country_name << endl;

    return 0;
}