#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long int> getThree(long long int a, long long int b, long long int c){
	long long int x,y,z,l,m,n,p=0;
	x = max(a,max(b,c));
	z = min(a,min(b,c));
	y = a+b+c-x-z;

	vector<long long int> res;

	if(x==y && y!=z){
		if((x-z)%2 == 1){
			l = x;
			m = z;
			n = x + x-z;
			p = z - (x-z);	
			res.push_back(p);
		}else{
			l = x;
			m = z;
			n = (x+z)/2;
		}
	}else if(x!=y && y==z){
		if((x-y)%2==1){
			l = x;
			m = y;
			n = x + x-y;
			p = y - (x-y);
			res.push_back(p);
		}else{
			l = x;
			m = y;
			n = (x+y)/2;
		}
	}else{
		if(y-x != z-y){
			return res;
		}
	}

	res.push_back(l);
	res.push_back(m);
	res.push_back(n);
	cout << endl << "the three possibilities are: " << l << " " << m << " " << n << " "<< p <<endl;
	return res;
}

int main(){
	long long int n;
	cin >> n;
	long long int x;

	bool sameTillNow = true;
	long long int A[3] = {0l,0l,0l};
	vector<long long int> B;

	for(int i=0; i< n; i++){
		cin >> x;
		if(i<3){
			A[i] = x;
			if(i==2){
				if(A[0]==A[1] && A[0]==A[2]) {
					sameTillNow = true;
				}else{
					sameTillNow = false;
					B = getThree(A[0],A[1],A[2]);
					if(B.size()==0){
						cout<<"NO";
						return 0;
					}
				}
			}
		}else{
			if(sameTillNow){
				if(x == A[0]){
					continue;
				}else{
					A[2] = x;
					sameTillNow = false;
					B = getThree(A[0],A[1],A[2]);
					if(B.size()==0){
						cout<<"NO";
						return 0;
					}
				}
			}else{
				if(x == B[0] || x == B[1] || x == B[2]){
					continue;
				}else{
					if(B.size()==4){
						if(x == B[3]){
							continue;
						}
					}
					cout << "NO";
					return 0;
				}
			}
		}		

	}
	
	cout << "YES";
	


	return 0;
}