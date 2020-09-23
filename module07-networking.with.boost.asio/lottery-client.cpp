#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::tcp;

void client(int sequence_id) {
    try {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query("192.168.130.132", "7001");
        tcp::resolver::iterator endpoint = resolver.resolve(query);
        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint);
        while (true) {
            boost::array<char, 128> buffer;
            boost::system::error_code error;
            auto length = socket.read_some(boost::asio::buffer(buffer), error);
            if (error == boost::asio::error::eof) break;
            else if (error)
                throw boost::system::system_error(error);
            std::cerr << std::this_thread::get_id() << ", " << sequence_id << ": ";
            std::cerr.write(buffer.data(), length);
            // std::cerr << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

}

int main(int argc, char *argv[]) {

    std::thread t1(client,1);
    std::thread t2(client,2);
    std::thread t3(client,3);
    std::thread t4(client,4);
    std::thread t5(client,5);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}