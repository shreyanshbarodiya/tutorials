#include <iostream>

using namespace std;

int main(){
	int n, m, k;
	int a[101];

	cin >> n >> m >> k;

	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

	int dist = 0;
	int min_dist = 10000;
	for(int i=1; i<=n; i++){
		if(a[i] == 0 || a[i] > k){
			continue;
		}
		dist = (i-m > 0) ? (i-m) : (m-i);
		if(dist < min_dist){
			min_dist = dist;
		}
	}

	cout << 10*min_dist << endl;

	return 0;
}