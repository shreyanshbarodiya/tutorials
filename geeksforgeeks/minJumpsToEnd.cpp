#include <iostream>
#include <climits>

using namespace std;

int minJumps(int a[], int l, int r){
	int maxFromL = l + a[l];

	if(l==r){
		return 0;
	}

	if(maxFromL>=r){
		return 1;
	}


	int x, mini = INT_MAX;

	for(int i=l+1; i<=maxFromL; i++ ){
		x = minJumps(a,i,r);
		if(x < mini){
			mini = x;
		}
	}

	return x+1;
}

int main(){
	int n;
	cin >> n;

	// n<25 for now and a[i] > 0

	int a[25];

	for(int i=0; i<n; i++){
		cin >> a[i]; 
	}

	cout << minJumps(a,0,n-1);

	return 0;
}