#include <iostream>

using namespace std;

long long int mdp(long long int a[],long long int b[], int n, int m ){
	long long int answer = 0;
	if(n==m){
		for(int i=0; i<m; i++){
				answer+= a[i]*b[i];
		}
		return answer;
	}else if(m>n){
		return 0;
	}else{
		
	}
}

int main(){
	int t,n,m;
	cin >> t;
	long long int a[1000];
	long long int b[1000];
	long long int answer=0;


	for(int t0=0; t0<t; t0++){
		cin >> n >> m;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		for(int i=0; i<m; i++){
			cin >> b[i];
		}

		if(n>m){
			cout << mdp(a,b,n,m);
		}else if(n<m){
			cout << mdp(b,a,m,n);
		}else{
			for(int i=0; i<m; i++){
				answer+= a[i]*b[i];
			}
			cout << answer;
		}

	}



	return 0;
}