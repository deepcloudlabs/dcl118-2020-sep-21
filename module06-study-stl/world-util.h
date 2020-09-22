#ifndef __world_util_h__
#define __world_util_h__

#include "city.h"
#include "country.h"

#include <memory>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

extern std::map<int,std::shared_ptr<world::city>> cities;
extern std::map<std::string,std::shared_ptr<world::country>> countries;

void create_cities();
void create_countries();
void create_world();

#endif