#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	int n,k;
	int K[1001];
	int y=0;

	for(int t0=0; t0<t; t0++){
		cin >> n >> k;
		int a[1001]={0};

		for(int i=1; i<=k; i++){
			cin >> K[i];
			a[K[i]]++;
		}

		y=a[1];
		cout << a[1] << " ";
		for(int i=2; i<=n; i++){
			a[i]= a[i]+a[i-1];
			cout << a[i] << " ";
		}

		cout <<endl;


	}

	return 0;
}