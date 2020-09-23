#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>
#include <algorithm>
#include <utility>
#include <string>
#include <sstream>
#include <boost/asio.hpp>

using namespace std;
using boost::asio::ip::tcp;

namespace std {
    template<typename T>
    std::string to_string(const T &n) {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}

class session : public std::enable_shared_from_this<session> {
public:
    session(tcp::socket socket) : socket_(move(socket)), mt(rd()), dist(1, 49) {
    }

    void start() {
        generateLotteryNumbers();
        do_write();
    }

private:
    void generateLotteryNumbers() {
        numbers.empty();
        while (numbers.size() < 6) {
            int candidate = dist(mt);
            if (find(numbers.begin(), numbers.end(), candidate) == numbers.end())
                numbers.push_back(candidate);
        }
        sort(numbers.begin(), numbers.end());
        _buffer.empty();
        for (auto x: numbers) {
            _buffer.append(std::to_string(x)).append(",");
        }
        _buffer.erase(_buffer.begin() + _buffer.size() - 1);
        _buffer.append("\n");
    }

    void do_write() {
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(_buffer.c_str(), _buffer.size()),
                                 [this, self](boost::system::error_code ec, std::size_t) {
                                 });
    }

    tcp::socket socket_;
    enum {
        max_length = 1024
    };
    char data_[max_length];
    string _buffer;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<int> dist;
    vector<int> numbers;
};

class server {
public:
    server(boost::asio::io_service &io_service, short port)
            : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
              socket_(io_service) {
        do_accept();
    }

private:
    void do_accept() {
        acceptor_.async_accept(socket_,
                               [this](boost::system::error_code ec) {
                                   if (!ec) {
                                       std::make_shared<session>(std::move(socket_))->start();
                                   }

                                   do_accept();
                               });
    }

    tcp::acceptor acceptor_;
    tcp::socket socket_;
};

int main(int argc, char *argv[]) {
    try {
        boost::asio::io_service io_service;
        server s(io_service, std::atoi("7001"));
        cerr << "Server is running at port 7001" << endl;
        io_service.run();
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}