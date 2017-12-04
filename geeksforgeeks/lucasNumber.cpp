#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n;
	long long int l[101];
	l[0] = 2;
	l[1] = 1;

	for(int i=2; i<=100; i++){
		l[i] = (l[i-1] + l[i-2])%1000000007;
	}

	for(int t0=0; t0<t; t0++){
		cin >> n;
		cout << l[n]%1000000007 << endl;

	}

	return 0;
}