#include <iostream>

using namespace std;


int findMaxOnesAfterFlipped(int a[], int n){
	int dp[n][n];

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			dp[i][j]=0;
		}
	}

	int max = 0, maxi=-1, maxj=-1;
	for(int i=0; i<n; i++){
		dp[i][i] = (a[i]==0)? 1 : -1;
		if(dp[i][i]>max){
			max = dp[i][i];
			maxi = i;
			maxj = i;
		}
	}

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			dp[i][j] = (a[j]==0)? dp[i][j-1]+1 : dp[i][j-1]-1;  
			if(dp[i][j]>max){
				max = dp[i][j];
				maxi = i;
				maxj = j;
			}	
		}
	}

	int answer = 0; 
/*	cout << "max = " << max << " and indices = ";
	cout << maxi << "-" <<  maxj << endl;*/

/*	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << dp[i][j] << "	";
		}
		cout << endl;
	}*/

	if(maxi == -1){
		for(int i=0; i<n; i++){
			answer+=a[i];
		}
		return answer;
	}else{
		for(int i=0; i<n; i++){
			if(i<maxi){
				answer+=a[i];
			}else if(i<=maxj){
				if(a[i]==0) answer++;
			}else{
				answer+=a[i];
			}
		}
		return answer;
	}
}

int main(){
	int t, n;
	int a[10000];

	cin >> t;

	for(int t0=0; t0<t; t0++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}

		cout << findMaxOnesAfterFlipped(a, n) << endl;
	}

	return 0;
}