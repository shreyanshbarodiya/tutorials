#include <iostream>

using namespace std;

int main(){
	int n,m,temp=0;
	char c;
	cin >> n >> m;

	for(int i=0; i<m*n; i++){
		cin >> c;
		if(c == 'C' || c=='M' || c=='Y' || c=='G'){
			temp =1;
			break;
		}

	}

	if(temp == 1){
		cout << "#Color";
	}else{
		cout << "#Black&White";
	}

	return 0;
}