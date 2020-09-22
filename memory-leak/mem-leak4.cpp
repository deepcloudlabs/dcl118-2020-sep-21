#include <iostream>

using namespace std;


int main(){
   int i, j;
   int a[10]={1,2,3,0}, b[9];
   for ( i = 0; i < 10; i++ ) {
      if (a[i])
      j = a[i];
      b[i] = j;
   }
   return 0;
}
