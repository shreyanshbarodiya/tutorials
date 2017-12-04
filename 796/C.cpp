#include <iostream>
#include <list>

using namespace std;

long long int maxStrength(list<int> adj[], int n, int start, long long int a[]){
	int neighbour;
	for(list<int>::iterator it = adj[start].begin(); it!= adj[start].end(); it++){
		neighbour = *it;
		it = adj[start].erase(it);
		
	}
}

int main(){
	int n;
	long long int a[300001];
	list<int> adj[300001];

	int x, y;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	return 0;
}