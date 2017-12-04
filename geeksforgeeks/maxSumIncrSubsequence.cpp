#include <iostream>
#include <climits>

using namespace std;

int maxSumIncrSub(int a[], int n){
	int dp[n];
	for(int i=0; i< n; i++){
		dp[i] = a[i];
	}

	int max= INT_MIN, curr;
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i]>a[j] && a[i]+dp[j]>dp[i]){
				dp[i] = a[i] + dp[j];
			}
		}
		if(dp[i]>max){
			max = dp[i];
		}
	}
	return max;
}

int main(){
	int n;
	int a[101];

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	cout << maxSumIncrSub(a, n);

}