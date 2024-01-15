#include <iostream>
using namespace std;

bool oddlinear(int n) {
	if(n <= 1 || n%2 != 0)
		return true;
	if(n%2 == 0)
		return false;
	return oddlinear(n/10);
}

bool oddtail(int n) {
	if(n <= 1)
	
}

int main() {
	
	cout << boolalpha;
	cout << oddlinear(123) << endl;
	cout << oddlinear(222) << endl;
	
	return 0;
}
