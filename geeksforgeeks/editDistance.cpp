#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int min(int x, int y, int z){
	return min(min(x,y),z);
}

int editDistRecursion(string s1, string s2, int m, int n){
	if(m==0){
		return n;
	}

	if(n==0){
		return m;
	}

	if(s1[m-1]==s2[n-1]){
		return editDistRecursion(s1,s2,m-1,n-1);
	}	
	return 1 + min( editDistRecursion(s1,s2,m,n-1),
					editDistRecursion(s1,s2,m-1,n),
					editDistRecursion(s1,s2,m-1,n-1)
		);
}

int editDistTabulation(string s1, string s2, int m ,int n){
	int dp[m+1][n+1];

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i==0){
				dp[i][j] = j;
			}else if(j==0){
				dp[i][j] = i;
			}else if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else {
				dp[i][j] = 1 + min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
			}
		}
	}

	return dp[m][n];

}

int dp[10][10];

int editDistMemoization(string s1, string s2, int m ,int n){
	int answer;
	int x,y,z;

	if(m==0){
		dp[m][n] = n;
		return n;
	}
	if(n==0){
		dp[m][n] = m;
		return m;
	}

	if(s1[m-1]==s2[n-1]){
		answer = (dp[m-1][n-1]==-1) ? editDistMemoization(s1,s2,m-1,n-1) : dp[m-1][n-1];
		dp[m][n] = answer;
		return dp[m][n];
	}else{
		x = (dp[m][n-1]==-1)? editDistMemoization(s1,s2,m,n-1) : dp[m][n-1];	
		y = (dp[m-1][n]==-1)? editDistMemoization(s1,s2,m-1,n) : dp[m-1][n];	
		z = (dp[m-1][n-1]==-1)? editDistMemoization(s1,s2,m-1,n-1) : dp[m-1][n-1];
		dp[m][n] = 1 + min(min(x,y),z);	
		return dp[m][n];
	}

}

int main(){

	string str1 = "sunday";
	string str2 = "saturday";
//	cout << editDistRecursion(str1, str2, str1.length(), str2.length());
//	cout << editDistTabulation(str1, str2, str1.length(), str2.length());
	
	for(int i=0;i<10; i++){
		for(int j=0;j<10; j++){
			dp[i][j] = -1;
		}
	}

	cout << editDistMemoization(str1, str2, str1.length(), str2.length());
	return 0;
}