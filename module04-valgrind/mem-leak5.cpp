#include <iostream>

using namespace std;


int main(){
   int *p= new int[1024];
   int *q= p;
   for (int i=0;i<1024;++i,++q)
   {  
       cerr << hex << q << ": " << dec << i << endl;
       *q= i;
   }
   delete[] p;
   return 0;
}
