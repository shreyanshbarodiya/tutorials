#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string s;
	cin >> s;
	string r(s.rbegin(), s.rend());

	int cnt = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i]!=r[i]){
			cnt++;
		}
	}

	if(cnt==2){
		cout << "YES" << endl;
	}else{
		if(cnt==0 && s.length()%2==1){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	return 0;
}