#include <iostream>

#include <bsoncxx/builder/basic/array.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

int main(int, char **) {

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    auto db = conn["hr"];

    mongocxx::collection employees = db["employees"];

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value programmer = builder
            << "fullname" << "Jack Bauer"
            << "birthYear" << 1962
            << "salary" << 10000
            << "languages" << bsoncxx::builder::stream::open_array
            << "java" << "c++" << "golang"
            << bsoncxx::builder::stream::close_array
            << "address" << bsoncxx::builder::stream::open_document
            << "zipcode" << 34212
            << "city" << "istanbul"
            << "country" << "turkey"
            << bsoncxx::builder::stream::close_document
            << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view view = programmer.view();

    bsoncxx::stdx::optional<mongocxx::result::insert_one> result =
            employees.insert_one(view);

}
