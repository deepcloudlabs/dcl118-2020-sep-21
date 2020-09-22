#include <iostream>

/*
 * Memory Layout:
 *         Text: main(),fun(),Circle::area(),Circle::circumference()
 *         Data: data(global), fun::y, Circle::z
 *         Stack: Automatic Memory Management -> Scope {} (No Memory Leak)
 *         Heap: Dynamic Memory Allocation -> new/delete -> Problem: Memory Leak
 *              new/delete: cost
 *         C++ ( gun() -> 10Microsec) vs (C#, Java, JS: Managed Platform -> GC (10 microsec, 1ms)-> Pause, Latency, new: fast)
*/
int data;

class Circle {
    static int z; // declaration
public:
    double area();
    double circumference();
};
int Circle::z; // definition

void fun(int x){
    static int y;
    int i; // local -> Stack
    Circle c; // object -> memory allocation -> constructor
    // return -> success
    // throw exception -> fail
} // end of scope -> destructor Circle::~Circle()

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
