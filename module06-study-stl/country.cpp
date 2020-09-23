#include "country.h"

namespace world {
    country::country(const std::string &code, const std::string &name, const std::string &continent, int population,
                     double surface_area, double gnp, int capital_id) {
        this->code = code;
        this->name = name;
        this->continent = continent;
        this->population = population;
        this->surface_area = surface_area;
        this->gnp = gnp;
        this->capital_id = capital_id;
    }

    country::country(const std::string &code, const std::string &name, const std::string &continent, int population,
                     double surface_area, double gnp, int capital_id, std::vector<std::shared_ptr<world::city>> &cities,
                     std::shared_ptr<world::city> &capital) {
        this->code = code;
        this->name = name;
        this->continent = continent;
        this->population = population;
        this->surface_area = surface_area;
        this->gnp = gnp;
        this->capital_id = capital_id;
        this->cities = cities;
        this->capital = capital;
    }
};

std::ostream &operator<<(std::ostream &out, const world::country &_country) {
    out << "country [ code=" << _country.code
        << ", name=" << _country.name
        << ", population=" << _country.population
        << ", surface_area=" << _country.surface_area
        << ", gnp=" << _country.gnp
        << ", continent=" << _country.continent
        << ", # of cities= " << _country.cities.size()
        << " ]";
    return out;
}
