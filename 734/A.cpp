#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;
	int a=0;
	for(int i=0; i< s.length(); i++){
		if(s[i]=='A'){
			a++;
		}
	}

	if(2*a==n){
		cout<<"Friendship";
	}else if(2*a>n){
		cout<<"Anton";
	}else{
		cout<<"Danik";
	}


	return 0;
}