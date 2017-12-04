#include <iostream>

using namespace std;

int main(){
	int n, m, k;
	bool h[1000001] = {false};
	int u, v;

	cin >> n >> m >> k;

	int x;
	int bone = 1;
	bool holeAtOne = false;

	if(n!=m){
		for(int i=1; i<=m; i++){
			scanf("%d",&x);
			h[x] = true;
			if(x==1){
				holeAtOne = true;
				break;
			}	
		}		
	}else{
		holeAtOne = true;
	}
	
	if(!holeAtOne){
		for(int i=1; i<=k; i++){
			if(h[bone]){
				break;
			}else{
				scanf("%d%d",&u,&v);
				if(bone == u){
					bone = v;
				}else if(bone == v){
					bone = u;
				}
			}
		}		
	}	

	cout << bone << endl;

	return 0;
}