#include <iostream>
class Circle {};
class A {
    int *p;
    // pointer, resource (file, socket, connection, ...)
    // Resource Management:  i. Acquire resource: new
    //                      ii. use resource: *, ->
    //                     iii. Release resource: delete
    // Responsibility: SRP -> Resource Management -> SharedPtr, UniquePtr
    // 1. Copy Constructor
    // 2. Move Constructor (since c++11)
    // 3. Assignment Operator
    // 4. Destructor

    // value object: Address, Circle, ...
    // 1. Copy Constructor
    // 2. Assignment Operator
public:
    explicit A(int value) : p(new int(value)) {
        std::cout << "A(int value)" << std::endl;
    }

    A(const A &other) { // copy constructor
        std::cout << "A(const A &other) : copy constructor" << std::endl;
        this->p = new int(other.p[0]);
    }

    A(A &&other) { // move constructor
        std::cout << "A(A &&other) : move constructor" << std::endl;
        this->p = other.p;
        other.p = nullptr;
    }

    A &operator=(const A &right) {
        std::cout << "operator=(const A& right) : assignment operator" << std::endl;
        if (this->p != nullptr) delete this->p;
        this->p = new int(*right.p);
    }

    A &operator=(A &&right) {
        std::cout << "operator=(A&& right) : assignment operator" << std::endl;
        this->p = right.p;
        right.p = nullptr;
    }

    virtual ~A() {
        std::cout << "~A() : destructor" << std::endl;
        if (this->p != nullptr)
            delete this->p;
    }
};

template<typename T>
void swap1(T &x, T &y) { // Memory consumption is high
    T tmp(x);
    x = y;
    y = tmp;
}

template<typename T>
void swap2(T &x, T &y) { // Memory efficient
    T tmp(std::move(x));
    x = std::move(y);
    y = std::move(tmp);
}

int main() {
    A o1{549}, o2{108}; // stack object
    A o3 = o2; // Copy constructor
    A o4(o2); // Copy constructor
    A o5(std::move(o2)); // Move constructor, move converts o2 to r-value
    // destructor: o5 -> o4 -> o3 -> o2 -> o1
    swap1(o1, o2);
    swap2(o1, o2);
}
