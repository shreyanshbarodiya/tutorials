#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c_two(int n){
	return n*(n-1)/2;
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;

	int c[1001];
	vector<int> V[1001];
	vector<int> val;

	for(int i=1; i<=k; i++){
		cin >> c[i];
	}
	
	int x,y;
	for(int i=1; i<=m; i++){
		cin >> x >> y;
		V[x].push_back(y);
		V[y].push_back(x);

	}

	for(int i=1; i<=k; i++){
		val.push_back(V[c[i]].size());
	}

	int total = 0;
	sort(val.begin(), val.end());

	for(int i=0; i<val.size(); i++){
		total += val[i];
	}

	int answer = c_two(val[0]+(n-total));

	for(int i=1; i<val.size(); i++){
		answer += c_two(val[i]);
	}

	cout << answer - m;

	return 0;
}