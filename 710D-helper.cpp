#include <iostream>
#include <vector>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	long long a = 105, b = 104;

	cout << gcd(a,b);

	return 0;
}