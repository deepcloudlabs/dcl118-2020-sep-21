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

std::map<int,std::shared_ptr<world::city>> cities;
std::map<std::string,std::shared_ptr<world::country>> countries;

int main(int argc, char* argv[]){
	create_world();


	std::set<std::string> continents;
	for (auto& ctry : countries){
	    continents.insert(ctry.second->continent);
	}
	for (auto& continent: continents){
		cout << continent << endl;	
	}
	// functional programming, stl algorithms, lambda expression
	return 0;
}