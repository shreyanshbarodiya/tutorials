#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;


bool storeFind(int * array, int x, int len);

int main(){
	int n,m,k,u,v, temp;
	int s;
	int l;
	cin >> n >> m >> k;
	
	int *stores = (int *) malloc(k* sizeof(int));

	int **adj = (int **)malloc(n * sizeof(int *));

    for (int i=0; i<n; i++){
         adj[i] = (int *)malloc(n * sizeof(int));
    }

    for(int i=0; i<n; i++){
    	for(int j=0; j<n ; j++){
    		adj[i][j] = 1000000000;
    	}
    }
	
	for(int i=0; i<m ; i++){
		cin >> u >> v >> l;
		if(adj[u-1][v-1] > l ){
			adj[u-1][v-1] = l;
			adj[v-1][u-1] = l;
		}
	}

	for(int i=0; i<k ; i++){
		cin >> temp;
		stores[i] = temp-1;
	}

	int min = 1000000000;
	for(int i=0; i < k ; i++){
		s = stores[i] ;
		for(int j=0; j<n ; j++){
			if(!storeFind(stores, j,k )){
				if(min > adj[s][j] ){
					min = adj[s][j];
				}
			}
		
		}
	}


	if(min == 1000000000){
		cout<< -1;
	}else{
		cout << min;
	}

	free(stores);
	for (int i=0; i<n; i++){
         free(adj[i]);
    }

	free(adj);


return 0;
}

bool storeFind(int * array, int x, int len){
	for(int i=0; i < len ; i++){
		if(array[i]==x){
			return true;
		}
	}

	return false;
}