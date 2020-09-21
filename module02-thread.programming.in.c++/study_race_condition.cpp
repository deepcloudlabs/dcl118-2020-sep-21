#include <thread>
#include <vector>
#include <iostream>
#include <mutex>
#include <atomic>

int data = 0;
std::mutex mut;
// 1) Mutex -> Lock -> Parking -> Low Throughput
// 2) Lock-free : atomic variables -> CPU (intel)  -> Not parking  -> High Throughput
std::atomic<int> atomic_data(0);

void fun(){
    for (auto i=0;i<2000000;++i){
        std::lock_guard<std::mutex> lock(mut); // (1) running (2,3,4) parking
        data++; // race: global variable: resource (memory)
    }
}

void atomic_fun(){
    for (auto i=0;i<2000000;++i){
        atomic_data++;
    }
}

int main(){ // not thread-safe -> Lock, Lock-free (atomic) -> thread-safe
    std::thread threads[]{
        std::thread(atomic_fun),
        std::thread(atomic_fun),
        std::thread(atomic_fun),
        std::thread(atomic_fun)
    };
    for (auto& t : threads) t.join();
    std::cerr << "data: " << atomic_data << std::endl;
}