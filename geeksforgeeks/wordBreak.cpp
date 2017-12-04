#include <iostream>
#include <string>

using namespace std;

bool inDict(string s, string dict[], int n){
	for(int i=0; i<n; i++){
		if(dict[i].compare(s) == 0){
			return true;
		}
	}
	return false;
}

int canBeBroken(string s, string dict[], int n){
	if(s.length()==0){
		return 1;
	}

	for(int i=0; i<=s.length(); i++){
		if(inDict(s.substr(0,i), dict, n)){
			if(canBeBroken(s.substr(i), dict, n) == 1){
				return 1;
			}
		}
	}

	return 0;
}

int main(){
	int T,n;
	string dict[12];
	string str;

	cin >> T;

	for(int t=0; t<T; t++){
		cin >> n;

		for(int i=0; i<n; i++){
			cin >> dict[i];
		}

		cin >> str;

		cout << canBeBroken(str, dict, n) << endl;
	}


	return 0;
}