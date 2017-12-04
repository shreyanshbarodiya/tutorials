#include <iostream>

using namespace std;

int main(){
	long long int n;
	cin >> n;
	int x;
	x = n%4;

	if(n==0){
		cout<<1;
	}else{
		switch(x){
			case 1:
				cout<<8;break;
			case 2:
				cout<<4;break;
			case 3:
				cout<<2;break;
			case 0:
				cout<<6;break;
		}	
	}

	return 0;
}