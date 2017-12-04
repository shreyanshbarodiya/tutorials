#include <iostream>
#include <string>

using namespace std;

int main(){
	string in;
	cin >> in;

	char c = in[0];
	char n = in[1];

	if(c == 'a'){
		if(n == '1' || n == '8'){
			cout << 3;
		}else{
			cout << 5;
		}
		return 0;
	}
	if(c == 'h'){
		if(n == '1' || n == '8'){
			cout << 3;
		}else{
			cout << 5;
		}
		return 0;
	}
	if(n == '1'){
		if(c == 'a' || c == 'h'){
			cout << 3;
		}else{
			cout << 5;
		}
		return 0;
	}
	if(n == '8'){
		if(c == 'a' || c == 'h'){
			cout << 3;
		}else{
			cout << 5;
		}
		return 0;
	}
	cout << 8;

	return 0;
}