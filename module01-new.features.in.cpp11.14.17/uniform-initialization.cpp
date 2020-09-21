
#include <initializer_list>

// Memory: variables: Data, Stack, Heap (new/delete), method/function: Text
int i; // global, value: Data

struct P {
    P(int x,int y){}
    P(std::initializer_list<int> inits){
};
void fun(){
    P p1(2,4); // P(int,int)
    P p2{3,5}; // P(std::initializer_list<int>)
    P p3{1,3,5,7,9}; // P(std::initializer_list<int>)
    P p4 = {3,5}; // P(std::initializer_list<int>)
}
int main() {
    static int k = 108; // local, value -> Data
    int j; // local, value: Stack
    int *p = new int[42]; // local, pointer -> an array in HEAP
    // pointer: memory address (Data/Stack/Heap)
    p = &j; // points to memory in stack
    p = &i; // points to memory in data
    // uniform initialization
    int m{}; // int m=0;
    int n{42}; // int n=42;
    int x1(5.3); // x1 = 5 automatically narrowing
    int x2 = 5.3; // x2 = 5
    // int x3{5.3}; // Error!
    // int x4 = {5.3}; // Error
    short lost[]{4,8,15,16,23,42}; // stack
    int *prime = new int[]{2,3,5,7,11,13}; // heap
}