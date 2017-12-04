#include <iostream>

using namespace std;

int findMinimumHours(int n){
	if(n<=12){
		if(n==12||n==10){
			return 1;
		}else{
			return -1;
		}
	}else{
		int a= findMinimumHours(n-12);
		int b= findMinimumHours(n-10);
		if(a!=-1){
			return 1+a;
		}else if(b!=-1){
			return 1+b;
		}else{
			return -1;
		}
	}
}

int main(){
	int t,n;
	cin >> t;

	for(int t0=0; t0<t; t0++){
		cin >> n;
		cout << findMinimumHours(n) << endl;

	}



	return 0;
}