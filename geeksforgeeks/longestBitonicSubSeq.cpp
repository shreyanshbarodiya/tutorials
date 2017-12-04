#include <iostream>
#include <climits>

using namespace std;

int findLongestBitonic(int a[], int n){
	int lis[n], lds[n];

	for(int i=0; i<n; i++){
		lis[i] = 1;
		lds[i] = 1;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i]>a[j] && lis[j]+1>lis[i]){
				lis[i] = lis[j] + 1;
			}
		}
	}

	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(a[i]>a[j] && lds[j]+1>lds[i]){
				lds[i] = lds[j] + 1;
			}
		}
	}

	int max=INT_MIN;

	for(int i=0; i<n; i++){
		if(lis[i]+lds[i]>max){
			max = lis[i]+lds[i];
		}
	}

	return max-1;
}

int main(){	
	int a[] = {12, 11, 40, 5, 3, 1};
	int n = 6;

	cout << findLongestBitonic(a, n);

	return 0;
}