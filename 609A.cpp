#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n,m,sum=0 ;
	cin >> n >> m;
	vector<int> a(n);
	for(int i=0; i<n ; i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	int j;
	for(j=0; j<n ; j++){
		if(sum>=m){
			break;
		}
		sum += a[j];
	}

	cout << j;

}