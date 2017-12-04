#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int x;
	vector<int> A(m+1,0);
	for(int i =0; i<n; i++){
		cin >> x;
		A[x] = A[x] + 1;
	}
	x=0;
	for(int i=1; i<=m ; i++){
		for(int j=i+1; j<=m ; j++){
			x+= A[i]*A[j];
		}
	}

	cout << x;
	return 0;
}

