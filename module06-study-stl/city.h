#ifndef __city_h__
#define __city_h__

#include "country.h"

#include <string>
#include <memory>
#include <iostream>


namespace world {
    // forward declaration
    struct country;
    struct city;

    struct city {
        int id;
        std::string name;
        std::string country_code;
        int population;
        std::shared_ptr<world::country> belongs_to;

        city(int id, const std::string &name, const std::string &country_code, int population);
    };

};

std::ostream &operator<<(std::ostream &out, const world::city &_city);

#endif