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
    std::shared_ptr<A> pa = std::make_shared<A>(); // new ----> delete
    std::shared_ptr<A> pb(new B());
    std::cerr << "counter (pa): " << pa.use_count() << std::endl;
    fun(pa);
    std::cerr << "counter (pa): " << pa.use_count() << std::endl;
    fun(pb);
}