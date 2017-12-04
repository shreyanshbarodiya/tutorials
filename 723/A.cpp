#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int X[100];
	int a,ans=0;

	for(int i=0;i<3;i++){
		cin >> X[i];
	}

	sort(X,X+3);
	a = X[1];
	for(int i=0;i<3;i++){
		ans += abs(X[i]-a); 
	}
	cout << ans;

	return 0;
}