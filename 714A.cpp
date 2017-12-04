#include <iostream>

using namespace std;

int main(){
	long long int l1,r1, l2,r2, k;

	cin >> l1 >> r1 >> l2 >> r2 >> k;

	long long  int left,right;

	if(l1 < l2){
		if(r1 < l2){
			cout << 0;
			return 0;
		}else{
			left = l2;
			if(r2 < r1){
				right = r2;
			}else{
				right = r1;
			}
		}
	}else{
		if(r2 < l1){
			cout << 0;
			return 0;
		}else{
			left = l1;
			if(r1 < r2){
				right = r1;
			}else{
				right = r2;
			}
		}
	}

	if( k<= right && k>=left ){
		cout << right -left << endl;
	}else{
		cout << right-left + 1 <<endl;
	}

	return 0;
}