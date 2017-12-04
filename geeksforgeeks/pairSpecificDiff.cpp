#include <iostream>
#include <algorithm>

using namespace std;

int answer(int a[], int n, int x){

	if(n==0 || n==1){
		return 0;
	}

	int last_diff = a[n-1] - a[n-2];
	
	if(last_diff<x){
		return a[n-1]+a[n-2]+answer(a,n-2,x);
	}else{
		return answer(a,n-1,x);
	}
}

int main(){
	int t;
	cin >> t;
	int n,x;
	int a[100];
	
	for(int t0=0; t0<t; t0++){
		cin >> n;
		
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		
		cin >> x;

		sort(a, a+n);
		cout << answer(a,n,x) << endl;

	}







	return 0;
}