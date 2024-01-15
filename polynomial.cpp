#include <iostream>
using namespace std;

double h(double A[], int n, double x) {
	if(n == 0)
		return *A;
	return h(A+1, n-1, x) * x + (*A);
}

int main() {
	double P[] = {1, 2, 3}; // p(x) == 3x^2 + 2x + 1
	int n = 2;
	int x = 3;
	
	cout << h(P, n, x);
	
	return 0;
}
