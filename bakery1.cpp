#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

class nd_pair{
public:
	int neighbour;
	int distance;
};

bool storeFind(vector<int> array, int x, int len);

int main(){
	int n,m,k,u,v, temp;
	int s;
	int l;
	cin >> n >> m >> k;
	
//	int *stores = (int *) malloc(k* sizeof(int));
	vector<int> stores;
	vector< vector<nd_pair> > adj(n);

    nd_pair temp_pair;
	for(int i=0; i<m ; i++){
		cin >> u >> v >> l;
		temp_pair.neighbour = v-1;
		temp_pair.distance = l;
		adj[u-1].push_back(temp_pair);

		temp_pair.neighbour = u-1;
		temp_pair.distance = l;
		adj[v-1].push_back(temp_pair);

	}

	for(int i=0; i<k ; i++){
		cin >> temp;
		stores.push_back(temp-1);
	}

	int min = 1000000000;
	for(int i=0; i < k ; i++){
		s = stores[i] ;
		for(int j=0; j< adj[s].size() ; j++ ){
			if(!storeFind(stores, j,k )){
				if(min > adj[s][j].distance ){
					min = adj[s][j].distance;
				}
			}
		}
	}


	if(min == 1000000000){
		cout<< -1;
	}else{
		cout << min;
	}



return 0;
}

bool storeFind(vector<int> array, int x, int len){
	for(int i=0; i < len ; i++){
		if(array[i]==x){
			return true;
		}
	}

	return false;
}