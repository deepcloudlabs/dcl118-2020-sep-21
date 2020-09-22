#include "city.h"

namespace world {
	
	city::city(int id,const std::string& name,const std::string& country_code,int population){
		this->id= id;
		this->name= name;
		this->population= population;
		this->country_code= country_code;
	}
			
};

std::ostream& operator<<(std::ostream& out,const world::city& _city){
	out << "city [ id=" << _city.id 
		<< ", name=" << _city.name 
		<< ", " << *(_city.belongs_to)
		<< ", population=" 
		<< _city.population 
		<< " ]";
	return out;
}		