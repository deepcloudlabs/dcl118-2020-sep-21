#include <iostream>
#include <memory>

struct A {
    int i;
    A() {
        i= 0;
        std::cerr << "A()" << std::endl;
    }
    virtual void gun(){
        i++;
        std::cerr << "A::gun()" << std::endl;
    }
    virtual ~A() {
        std::cerr << "~A()" << std::endl;
    }
};

struct B: public A {
    B() {
        std::cerr << "B()" << std::endl;
    }
    void gun(){
        i++;
        std::cerr << "B::gun()" << std::endl;
    }
    virtual ~B() {
        std::cerr << "~B()" << std::endl;
    }
};

void fun(std::shared_ptr<A> p){

    p->gun();
    std::cerr << "counter: " << p.use_count() << std::endl;
}

// Thread-Safe Application
// Thread-Safe Class
int main(){
    // strong pointer : shared_ptr<>
    {
        std::shared_ptr<A> p1 = std::make_shared<A>(); // new ----> delete
        // weak pointer : weak_ptr
        std::weak_ptr<A> wp = p1;
        {
            std::shared_ptr<A> p2 = p1;
            if (p2) // always true
               p2->gun();
            {
                std::shared_ptr<A> p3 = p1;
                // p1 -> objA
                // p2 -> objA
                // p3 -> objA
                std::cerr << "counter: " << p3.use_count() << std::endl;
                p3->gun();
                p3.reset();
            }
            // p1 -> objA
            // p2 -> objA
            std::cerr << "counter: " << p2.use_count() << std::endl;
        }
        // p1 -> objA
        std::cerr << "counter: " << p1.use_count() << std::endl;
        p1.reset(); // object retention
        std::shared_ptr<A> p4 = wp.lock();
        if (p4){ // guard
            p4->gun();
            std::cerr << "counter (p4): " << p4.use_count() << std::endl;
        }
    } // End of scope for p1 -> count:0 -> delete -> A::~A()
    std::cerr << "done." << std::endl;
}