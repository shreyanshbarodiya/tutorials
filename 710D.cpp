#include <iostream>

using namespace std;

typedef long long ll;

long long calculateGCD(long long a, long long b){
	/*if(a==1 || b==1){
		return 1;
	}
	if(a-b == 1){
		return 1;
	}
	if(a == b){
		return a;
	}
	if(a>b){
		return calculateGCD(a-b,b);
	}else{
		return calculateGCD(a,b-a);
	}*/
	if(b==0){
		return a;
	}else{
		return calculateGCD(b,a%b);
	}
}

int main(){
	ll a1,b1,a2,b2,L,R;

	cin >> a1 >> b1 >> a2 >> b2 >> L >> R ;

	ll max_b = (b1>b2) ? b1 : b2;
	int temp = 1;
	if(R < max_b){
		cout<< 0;
		temp = 0;
		return 0;
	}

	ll gcd = calculateGCD(a1,a2);
	ll lcm = (a1*a2)/gcd;

	if(a1 == a2){
		if(b1!=b2){
			cout << 0;
			return 0;
		}else{
			if((L-b1)%a1==0 && (R-b1)%a2==0){
				cout << (R-L)/lcm +1;
			}else{
				cout << (R-L)/lcm ;
			}
			return 0;
		}
	}



	ll N = max_b;
	ll greater_a = (a1>a2) ? a1 : a2;
	ll greater_b = (a1==greater_a) ? b1 : b2;
	while((N-b1)%a1!=0 || (N-b2)%a2!=0){
		if((N-greater_b)%greater_a!=0){
			N++;
		}else{
			N = N + greater_a;
		}
	}

	ll count = 0;

	if(N<=R){
		while(N<L){
			N = N + lcm;
		}
		cout << (R - N)/lcm + 1 ;
/*		while(N < R){
			N = N + lcm;
			count++;
		}
		cout << count;*/
	}else{
		if(temp == 1){
			cout << 0;
		}
	}

	return 0;
}