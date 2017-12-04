#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  int mn=100000;
  
  for(int i=0;i<m;i++){
  	int a,b;
  	cin>>a>>b;
  	mn=min(mn,b-a+1);
  }

  cout<<mn<<endl;
  
  for(int i=0;i<n;i++){
	cout<<i%mn<<" ";  	
  } 

  return 0;
}