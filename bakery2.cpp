#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define maxn 100001

struct Edge
{
	int u, v, l;
	Edge(){}
};
Edge p[maxn];
bool ok[maxn];

int main()
{
	int n, m, k, i, minimum = INT_MAX, u, v, l;

	cin >> n >> m >> k;

	for(i = 0; i < m; i++){
		cin >> u >> v >> l; 
		p[i].u = u;
		p[i].v = v;
		p[i].l = l;
	}
	
	for(i = 0; i < k; i++){
		cin >> u;
		ok[u] = true;
	}

	for(i = 0; i < m; i++)
		
		if(ok[p[i].u] ^ ok[p[i].v]){
			if(p[i].l < minimum)
				minimum = p[i].l;
		}
	
	minimum = minimum == INT_MAX ? -1 : minimum;
	cout << minimum;
	return 0;
}