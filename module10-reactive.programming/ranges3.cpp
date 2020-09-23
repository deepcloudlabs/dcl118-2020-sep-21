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
#include <range/v3/view/group_by.hpp>
#include <range/v3/view/all.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/view.hpp>
#include <range/v3/action/sort.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/algorithm/for_each.hpp>

using namespace std;
using namespace world;
using namespace ranges;

std::map<int,std::shared_ptr<world::city>> cities;
std::map<std::string,std::shared_ptr<world::country>> countries;

auto group_by_gnp() {
    return
            view::group_by(
                    [](shared_ptr<country> a,shared_ptr<country> b) -> bool {
                        auto is_a_rich= a->gnp >= 25000.0 ;
                        auto is_b_rich= b->gnp >= 25000.0 ;
                        return is_a_rich == is_b_rich ;
                    }
            );
}

auto order_by_gnp = [](shared_ptr<country> &a,shared_ptr<country> &b) -> bool {
    return a->gnp < b->gnp ;
};

int main(int argc, char* argv[]){

    create_world();
    auto all= countries | view::values | to_vector | action::sort(order_by_gnp);
    auto rich_poor_countries= all | group_by_gnp() ;
    RANGES_FOR(auto cluster, rich_poor_countries)
                        {
                            RANGES_FOR(auto c, cluster)
                                                {
                                                    cout << *c << endl;
                                                }
                            cout << endl;
                        }

    return 0;
}