#include <iostream>

#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

int main(int, char**) {
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    bsoncxx::builder::stream::document document{};

    auto collection = conn["test108"]["coll42"];
    document << "_id" << "11111111110";
    document << "firstname" << "jack";
    document << "lastname" << "bauer";
    document << "birthyear" << 1956; // {"_id": "11111111110", "firstname": "jack", "lastname" : "bauer", "birthyear" : 1956}

    collection.insert_one(document.view());
    auto cursor = collection.find({});

    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}
