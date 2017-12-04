#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	string orig = s;
	int count=1;
	char c;
	string s2;

	for(int i=0; i<s.length(); i++){
		c = s[s.length()-1];
		s2 = s.substr(0,s.length()-1);
		s2 = c+ s2;
		s = s2;
		if(s == orig){
			break;
		}else{
			count++;
		}
	}

	cout << count;

	return 0;
}