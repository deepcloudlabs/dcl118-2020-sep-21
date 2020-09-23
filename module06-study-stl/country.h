
#ifndef __country_h__
#define __country_h__

#include "city.h"

#include <vector>
#include <memory>
#include <iostream>
#include <string>

namespace world {
    // forward declaration
    struct city;
    struct country;

    struct country {
        std::string code;
        std::string continent;
        std::string name;
        double surface_area;
        int population;
        double gnp;
        int capital_id;
        std::shared_ptr<world::city> capital;
        std::vector<std::shared_ptr<world::city>> cities;

        country(const std::string &, const std::string &, const std::string &, int, double, double, int);

        country(const std::string &, const std::string &, const std::string &, int, double, double, int,
                std::vector<std::shared_ptr<world::city>> &, std::shared_ptr<world::city> &);
    };
};

std::ostream &operator<<(std::ostream &, const world::country &);

#endif