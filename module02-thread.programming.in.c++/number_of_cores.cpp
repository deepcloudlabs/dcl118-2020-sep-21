#include <iostream>
#include <thread>

using namespace std;

int main(){
	cout << thread::hardware_concurrency() << " cores are available." << endl ;
    return 0;
}