#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	long long ans=0;
	cin>>n;
	priority_queue<int>s;
	int a;

	for(int i=0;i<n;i++){
		cin>>a;
		a-=i;
		s.push(a);
		if(s.top()>a){
			ans+=s.top()-a;
			s.pop();
			s.push(a);
		}
	}
	cout<<ans<<endl;
}