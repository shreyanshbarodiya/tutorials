#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;
typedef long long int ll;
int main(){
	int t;
	cin >> t;
	char c;
	string s;
	ll x;
	map<ll,int> m;

	for(int i=0; i<t; i++){
		cin >> c >> s;
		reverse(s.begin(),s.end());
		x=0;
		for(int j=0; j<s.length(); j++){
			if((s[j]-48)%2 != 0){
				x = x| (1<<j); // or x = x + (1<<j) -- OR  -- x = x + 2^j;
			}
		}

		if(c == '+'){
			m[x]++;
		}else if(c == '-'){
			m[x]--;
		}else{
			cout << m[x]<<endl;
		}
	}


	return 0;
}