#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int n,x,y;

	cin >> n >> x >> y;

	vector<long long int> v(n+1);

	v[1] = x;

	for(int i=2; i<n+1; i++){
		v[i] = min(v[i-1] + x, v[(i+1)/2] + y + (i%2)*x);
	}

	cout << v[n];
	return 0;
}