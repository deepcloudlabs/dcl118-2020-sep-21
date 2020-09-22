#include <iostream>
struct A {
   int x;
   A(int x): x(x){
       std::cout << "A(int)" << std::endl ;
   }
};
struct B: public A {
    int y;
    B(int x,int y): A(x), y(y){
       std::cout << "B(int,int)" << std::endl ;
    }
};
// llvm -> dependency tree
// optimization: -O{1,2,3,4}
// w/o optimiziation: inlining
class C{
    inline void fun(); // declaration
    // method -> automatically inlined
}; // declaration + definition

class Circle : public A {
    double x, y;
    double radius;
public:
    Circle() : Circle(1.) {
        std::cout << "Circle()" << std::endl;
    } // (1) -> (2) -> (4)
    // Circle(double radius) : x(0), y(0), radius(radius) {}
    Circle(double radius) : Circle(0., 0., radius) {
        std::cout << "Circle(double radius)" << std::endl;
    } // (2) -> (4)

    Circle(double x, double y) : Circle(x, y, 1) {
        std::cout << "Circle(double x, double y)" << std::endl;
    } // (3) -> (4)

    Circle(double x, double y, double radius) : x(x), y(y), // (4)
                                                radius(radius), A(x) {
        std::cout << "Circle(double x, double y, double radius)" << std::endl;
    }
};

int main(){
    B b(1,2);
    Circle circles[] {
        {},
        {100.0},
        {100.,200.},
        {100.0,200.,300.}
    };
}