#include <iostream>

using namespace std;


int main(){
   int *px = new int[1024];
   px[24]= 42;
   int *p= new int[1024];
   // p= p+52;
   delete []p;
   delete []px;
   return 0;
}
