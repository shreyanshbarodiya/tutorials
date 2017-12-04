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
	long long a1,b1,a2,b2,x,L,R;
	cin>>a1>>b1>>a2>>b2>>L>>R;
	long long p1=b1,p2=b2;
	b1=(b1%a1+a1)%a1;
	b2=(b2%a2+a2)%a2;

	long long lcm=(a1*a2)/gcd(a1,a2);
	L=L>p1?L:p1;
	L=L>p2?L:p2;
	if(a2>a1){
		swap(a1,a2);
		swap(b1,b2);
	}

	long long t=L+(a1+b1-L%a1)%a1;
	 x=t;
	bool pos=false;
	while(x<=R&&x<=t+lcm){
		if((x%a2+a2)%a2==b2&&(x%a1+a1)%a1==b1){
			pos=true;
			break;
		}
		x=x+a1;
	}

	
	if(pos)
	cout<<(R-x)/lcm+1;
	else
		cout<<0;
}