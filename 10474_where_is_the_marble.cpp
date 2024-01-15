#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int partition(int M[], int start, int end) {
	int pivot = M[end];
	int i = start-1;
	
	for(int j = start; j < end; j++) {
		if(M[j] < pivot) {
			i++;
			swap(M[i], M[j]);
		}
	}
	
	swap(M[i+1], M[end]);
	return (i+1);
}

void quick_sort(int M[], int start, int end) {
	if(start < end) {
		int i = partition(M, start, end);
		
		quick_sort(M, start, i-1);
		quick_sort(M, i+1, end);
	}
}

int first_occurence(int M[], int query, int left, int right) {
	if(left > right)
		return -1;
	int m = (left+right)/2;
	if(M[m]==query && (M[m-1]!=query || m==0))
		return m;
	else if(M[m] < query)
		return first_occurence(M, query, m+1, right);
	else
		return first_occurence(M, query, left, m-1);
}

int main() {	
	unsigned int N; // number of marble/s
	unsigned int Q; // number of queries by Meena
	
	int Marbles[N];
	int Queries[Q];
	
	int T = 1; // counter for each test case
	while(cin >> N >> Q) {
		if(N == 0 && Q == 0)
			break;
		
		for(int i = 0; i < N; i++)
			cin >> Marbles[i];
			
		for(int j = 0; j < Q; j++)
			cin >> Queries[j];
			
		// sort the numbers of marbles first, before searching
		quick_sort(Marbles, 0, N-1);
	
		cout << "CASE# " << T++ << ":" << endl;
		for(int k = 0; k < Q; k++) { // compare each query to numbers written in marbles
			int loc = first_occurence(Marbles, Queries[k], 0, N);
			
			if(loc == -1)
				cout << Queries[k] << " not found" << endl;
			else
				cout << Queries[k] << " found at " << loc+1 << endl;
		}
	}
	
	return 0;
}
