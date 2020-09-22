#include <iostream>

using namespace std;


int main(){
    int *p= new int[0];
    delete []p;
    return 0;
}
