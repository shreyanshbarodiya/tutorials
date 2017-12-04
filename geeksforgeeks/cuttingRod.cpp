#include <iostream>
#include <climits>

using namespace std;

int maxPriceObtainable(int price[], int n){
	if(n==0){
		return 0;
	}

	int answer, maxi = INT_MIN;
	for(int i=1; i<=n; i++){
		answer = price[i] + maxPriceObtainable(price, n-i);
		if(maxi < answer ){
			maxi = answer;
		}
	}
	return maxi;
}

int maxPriceObtainableTabulation(int price[], int n){
	int dp[n+1];
	dp[0] = 0;

	int answer, maxi = INT_MIN;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			answer = price[j] + dp[i-j]; 
			if(answer>maxi){
				maxi = answer;
			}
		}
		dp[i] = maxi;
	}
	return dp[n];
}	

int main(){
	int length;
	cin >> length;

	int price[100];

	for(int i=1; i<=length; i++){
		cin >> price[i];
	}

	cout << maxPriceObtainableTabulation(price, length) << endl;
	cout << maxPriceObtainable(price, length) << endl;


	return 0;
}