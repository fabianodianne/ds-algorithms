#include <iostream>
using namespace std;

int reverse(int n) {
	if(n < 10)
		cout << n;
	else {
		cout << n%10;
		return reverse(n/10);
	}
}

int main() {
	int n;
	
	cin >> n;
	
	reverse(n);
	
	return 0;
}
