#include <iostream>

using namespace std;


int main(){
	int n,m;
	int a[101];
	int l[101], r[101];
	int ans=0;
	int x;

	cin >> n >> m;

	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

	for(int i=1; i<=m; i++){
		cin >> l[i] >> r[i];
		x = 0;	
		for(int j=l[i]; j<=r[i]; j++){
			x+= a[j];
		}
		if(x>0){
			ans+=x;
		}
	}

	cout << ans;

	return 0;
}