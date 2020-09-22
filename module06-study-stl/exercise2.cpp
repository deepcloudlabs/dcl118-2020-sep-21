#include "city.h"
#include "country.h" 
#include "world-util.h" 

#include <set>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include <parallel/algorithm>
#include <numeric>

using namespace std;
using namespace world;

std::map<int,std::shared_ptr<world::city>> cities;
std::map<std::string,std::shared_ptr<world::country>> countries;
int y;
int main(int argc, char* argv[]){
	create_world();

	auto continentCountriesCounter= //TODO: Find the number of countries in each continent
	cout << "x=" << x << endl;

	for (auto& entry: continentCountriesCounter){
		cout << entry.first << ": " << entry.second << endl;
	}
		
	return 0;
}