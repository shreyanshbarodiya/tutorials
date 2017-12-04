#include <iostream>
#include <set>
using namespace std;


int main(){
	long long int n,a,b,i=0, l,m,r  ;
	set <int> s;
	
	cin>>n;
	
	while(i<n){
		cin>>a;
		s.insert(a);
		i++;
	}
	
	if(s.size()<=2 ){
		cout<<"YES";
	}else if(s.size() == 3){
		l = *s.begin();
		m = *(++s.begin());
		r = *(--s.end());
		if(2*m == l+r){
			cout<<"YES";
		}else{
			cout << "NO";
		}
	}
	else cout<<"NO";

	return 0;
}