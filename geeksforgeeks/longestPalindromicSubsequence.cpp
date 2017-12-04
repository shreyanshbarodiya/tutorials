#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int lps(string s, int i, int j){
	if(i==j){
		return 1;
	}
	if(i>j){
		return 0;
	}
	if(s[i]==s[j]){
		return 2 + lps(s,i+1,j-1);
	}else{
		return max(lps(s,i+1,j),lps(s,i,j-1));
	}
}

int lpsTabulation(string s, int n){
	int dp[n][n];

	for(int i=n-1; i>=0; i--){
		for(int j=0; j<n; j++){
			if(i==j){
				dp[i][j] = 1;
			}else if(i>j){
				dp[i][j] = 0;
			}else if(s[i]==s[j]){
				dp[i][j] = 2 + dp[i+1][j-1];
			}else{
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
			}
		}
	}

	return dp[0][n-1];

}

int main(){
	string s;
	cin >> s;

	cout << lpsTabulation(s,s.length()) << endl;
	cout << lps(s,0,s.length()-1) << endl;

}