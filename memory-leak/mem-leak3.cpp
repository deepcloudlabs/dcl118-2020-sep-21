#include <iostream>

using namespace std;


int main(){
    int x=1 ;
    int *p= new int[10];
    p[9]=42;
    cout << "x= " << x << endl;
    delete []p;
    return 0;
}
