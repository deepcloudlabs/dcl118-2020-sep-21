#include <iostream>

#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

// http://binkurt.blogspot.com/2015/02/mongodb-ile-calsmak.html
int main(int, char**) {


    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    auto db = conn["world"];
    // db.countries1.find({"continent": "Asia"})
    mongocxx::options::find opts{};
    opts.projection(document{} << "_id" << 0 << "name" << 1 << "population" << 1 << "continent" << 1 << finalize);
    auto cursor = db["countries1"].find({
        document{} << "continent" << "Asia" << finalize // {"continent": "Asia"}
    },opts);

    for (auto&& doc : cursor ) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
    auto continents = db["countries1"].distinct("continent", document{}.view());
    for (auto &&cont : continents)
        std::cout << bsoncxx::to_json(cont) << std::endl;
}
