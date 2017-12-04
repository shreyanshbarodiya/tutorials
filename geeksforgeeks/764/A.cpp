#include <iostream>

using namespace std;

int gcd(int n,int m){
	if(n==m)
		return n;
	if(n>m)
		return gcd(n-m,m);
	else
		return gcd(n,m-n);
}

int lcm(int x, int y){
	return (x*y)/gcd(x,y);
}

int main(){
	int n,m,z;

	cin >> n >> m >> z;

	int lc = lcm(n,m);
	int count= 0;
	for(int i=lc; i<=z; i+=lc,count++){

	}

	cout << count;

	return 0;
}