#include <iostream>
#include <string>

using namespace std;

int moves(string a, string b){
	string t = a;
	if(a.length()!=b.length()){
		return -100000;
	}

	char c ;
	int cnt = 0;
	for(int i=0; i<a.length(); i++){
		if(t==b){
			cnt = i;
			break;
		}
		c = t[0];
		t = t.substr(1);
		t.push_back(c);
	}

}
int main(){	
	int n;
/*	string s[51];

	cin >> n;

	for(int i=1; i<=n; i++){
		cin >> s[i];
	}
*/

	return 0;
}
