#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	int n,b,d;
	cin >> n >> b >> d;

	int x, curr = 0, count =0;
	for(int i=0; i<n ; i++){
		cin >> x;
		if(x > b){
			continue;
		}
		curr += x;
		if(curr > d){
			curr =0;
			count++;
		}
	}
	cout << count;
	return 0;
}