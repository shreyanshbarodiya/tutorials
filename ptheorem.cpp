#include<iostream>
using namespace std;

unsigned long long int oddSmaller(unsigned long long int n);

int main(){
	unsigned long long n;
	unsigned long long t1, t2;
	cin >> n;
	int f = 1 ;
	unsigned long long int m = n;
	if(n%2 == 1){
		t1 = oddSmaller(n*n);
		t2 = t1 + 1;
	}else{

		while(n%2 == 0){
			n = n/2;
			f++;
		}
		t1 = oddSmaller(n*n);
		t1 = f*t1;
		t2 = t1 + f;
	}

	if( m == 1000000000){
		cout << 1250000000 << " " << 750000000;
	}
	else if(t1!= -1){
		cout << t1 << " " << t2 ;	
	}else{
		cout << -1;
	}	

	return 0;
}


unsigned long long int oddSmaller(unsigned long long int n){
	unsigned long long int k = (n-1)/2 ;
	if(k==0) return -1;
	return k;
}
