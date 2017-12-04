#include <iostream>

using namespace std;

long long int a[200000];
long long int b[200000];

int main(){
	long long int n;
	cin >> n;

	for(long long int i = 0; i<n; i++){
		cin >> a[i];
	}

	bool sum=true;

	for(long long int i = 0; i<n; i++){
		if(!(n%2==0&&i==n/2)){
			sum = (sum)? false : true;
		}

		if(sum){
			b[n-i-1] = a[i];
		}else{
			b[i] = a[i];
		}
	}

	for(long long int i = n-1; i>=0; i--){
		cout << b[i] << " ";
	}

	return 0;
}