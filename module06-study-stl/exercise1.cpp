#include "city.h"
#include "country.h"
#include "world-util.h"

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <numeric>

using namespace std;
using namespace world;

std::map<int, std::shared_ptr<world::city>> cities;
std::map<std::string, std::shared_ptr<world::country>> countries;

int main(int argc, char *argv[]) {
    create_world();


    std::set<std::string> continents;
    for (auto &ctry : countries) { // external loop
        continents.insert(ctry.second->continent);
    }
    for (auto &continent: continents) {
        cout << continent << endl;
    }
    // functional programming, stl algorithms, lambda expression
    auto continentReducer = [&](
            std::set<std::string> &conts, std::pair<const std::string, std::shared_ptr<world::country>> &entry)
            -> std::set<std::string> & {
        auto ctry = entry.second;
        auto continent = ctry->continent;
        conts.insert(continent);
        return conts;
    };
    auto kitalar = std::accumulate( // internal loop
            countries.begin(),
            countries.end(),
            std::set<std::string>(),
            continentReducer);
    cout << "Functional way of thinking..." << endl;
    for (auto &continent: kitalar) {
        cout << continent << endl;
    }
    return 0;
}