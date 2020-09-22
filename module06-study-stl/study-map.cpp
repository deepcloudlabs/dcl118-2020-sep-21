#include <map>
#include <iostream>

int main(){
    std::map<std::string,int> area_codes{
            {"ankara", 312}, // "ankara" -> 312
            {"istanbul-avrupa", 212}, // "istanbul-avrupa" -> 212
            {"istanbul-anadolu", 216} // "istanbul-anadolu" -> 216
    };
    std::cout << "size: " << area_codes.size() << std::endl;
    std::cout << "empty?: " << area_codes.empty() << std::endl;
    std::cout << "\"ankara\" -> " << area_codes["ankara"] << std::endl;
    std::cout << "\"istanbul-anadolu\" -> " << area_codes.at("istanbul-anadolu") << std::endl;
    area_codes.insert(std::pair<std::string,int>("antalya",242));
    area_codes["izmir"] = 232;
    std::cout << "size: " << area_codes.size() << std::endl;
    auto areacode_pair = area_codes.find("izmir");
    if (areacode_pair == area_codes.end())
        std::cout << "i do not know \"edirne\"" << std::endl ;
    else
        std::cout << areacode_pair->first << ": " << areacode_pair->second << std::endl ;
    //c++11
    for (const auto& kv : area_codes)
        std::cout << kv.first << ": \t" << kv.second << std::endl ;
    // c++17
    for (const auto& [key,value] : area_codes)
        std::cout << key << ": \t" << value << std::endl ;
    // iterator
    // for (std::map<std::string,int>::iterator p = area_codes.begin(); // read-write
    for (auto p = area_codes.begin(); // read-write
         p != area_codes.end();
         ++p){
        std::cout << p->first << ": " << p->second << std::endl ;
    }
    return 0;
}