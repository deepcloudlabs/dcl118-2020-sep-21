#include <iostream>
#include <thread>
#include <future>
#include <pthread.h>
#include <unistd.h>
// OS: program -> process
/*
 * Multi-tasking: task -> process: Memory(Data, Text, Heap, Stack)
 *                   task1 -> process: Memory(Data, Text, Heap, Stack)
 *                   task2- > process: Memory(Data, Text, Heap, Stack)
 *                   Parent -> Child
 *                   Chrome -> Tab -> Multi Process Multi Thread
 *                   Oracle Database -> Multi Process Multi Thread
 *
 *                task -> thread -> Stack, Process(Data, Text, Heap)
 *                task1 -> thread -> Stack
 *                task2 -> thread -> Stack (Memory Consumption: Light Weight)
 *                create 1024 threads -> Memory: 1024 * Stack Size? ulimit -a -> 8M -> 8G
 *                FireFox -> Tab -> Thread
 *                MySQL, MongoDB -> Single Process, Multiple Thread
*/
// global data
int data = 100;

void task1() { // (1)
    std::cerr << "Task1 is started by " << std::this_thread::get_id() << std::endl;
    std::cerr << "Task1 is running..." << std::endl;
    for (auto k = 0; k < 10000; ++k) data++;
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cerr << "Task1 is done." << std::endl;
}

struct Task2 { // (2) : OOP
    // state
    int i;

    Task2() { i = 0; }

    void operator()() {
        std::cerr << "Task2 is started by " << std::this_thread::get_id() << std::endl;
        std::cerr << "Task2 is running..." << std::endl;
        for (auto k = 0; k < 10000; ++k) i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::cerr << "Task2 is done: " << i << std::endl;
    }
};

auto task3 = []() { // (3): (3) -> (2) // no side-effect!, stateless function, race condition!
    std::cerr << "Task3 is started by " << std::this_thread::get_id() << std::endl;
    std::cerr << "Task3 is running..." << std::endl;
    for (auto k = 0; k < 10000; ++k) data++;
    std::this_thread::sleep_for(std::chrono::milliseconds(4500));
    std::cerr << "Task3 is done." << std::endl;
};

long sequence(long n) { // 17 -> 52 -> 26 -> 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
    auto step = 0L;
    while (n > 1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        step++;
    }
    return step;
}

std::future<long> async_sequence(long n) {
    return std::async(sequence, n);
}

const int NUMBER_OF_CORES = sysconf(_SC_NPROCESSORS_ONLN);

int bind_self_to_core(int core_id) { // posix thread library
    core_id = core_id % NUMBER_OF_CORES;

    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(core_id, &cpuset);

    pthread_t current_thread = pthread_self();
    return pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset);
}

int core_id = 0;

void task_func() {
    bind_self_to_core(core_id++);
    // implement your task
}

int main() {
    std::thread t10(task_func);
    std::thread t11(task_func);
    std::thread t12(task_func);
    t10.join();
    t11.join();
    t12.join();

    Task2 task2;
    std::cerr << "app is started by " << std::this_thread::get_id() << std::endl;
    std::thread t1{task1};
    std::thread t2{task2};
    std::thread t3{task3};
    t1.join(); // blocking
    t2.join(); // blocking
    // t1.native_handle() // posix thread library: cpu affinity
    t3.join(); // blocking
    std::future<long> result = std::async(sequence, 101L);
    std::cerr << result.get() << std::endl; // get(): blocking
    auto async_result = async_sequence(549);
    // do something more important tasks
    std::cerr << async_result.get() << std::endl; // get(): blocking
    // reactive programming: Angular (rxjs) -> callback, React.js -> (fetch api), networking : boost.asio
    std::cerr << "done." << std::endl;
    return 0;
}
