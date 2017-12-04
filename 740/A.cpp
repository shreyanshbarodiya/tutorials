#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;



int main(){
	ll n, a, b, c;
	ll x,y,z;

	cin >> n >> a >> b >> c;

	if(n%4==0){
		x=0;
		y=0;
		z=0;
	}else if(n%4==1){
		x = c;
		y = a + b;
		z = 3*a;
	}else if(n%4==2){
		x = b;
		y = 2*a;
		z = 2*c;
	}else if(n%4==3){
		x = a;
		y = b+c;
		z = 3*c;
	}

	x = min(x,y);
	x = min(x,z);
	cout<< x;

	return 0;
}