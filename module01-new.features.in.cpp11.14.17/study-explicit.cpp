struct P {
    P(int x) {}
    P(int x, int y) {}

    explicit P(int x, int y, int z) {}
};
void fun(const P &){}

int main() {
    P p1(1, 2); // P(int,int)
    P p2{1, 2}; // P(int,int)
    P p3 = {1, 2}; // P(int,int), implicit version!

    P p = 42; // int -> P (implicit conversion)

    P p4(1, 2, 3); // P(int,int,int)
    P p5{1, 2, 3}; // P(int,int,int)
    // P p6 = {1,2,3}; // ERROR: explicit conversion!
    fun(P{1,2,3})
    fun({1,2}); // Implicit Conversion!
    fun(P{1,2,3}); // explicit!
}