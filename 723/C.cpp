#include <iostream>

using namespace std;

int n,m;
int B[2001]={0};
long long A[2001];

int findBWithMinValue(){
	int minV = 2001;
	int index;
	for(int i=1;i<=m;i++){
		if(B[i]<minV){
			minV= B[i];
			index = i;
		}
	}
	return index;
}

int main(){
	cin >> n >> m;

	int minB = n/m;
	int index;
	for(int i=1;i<=n;i++){
		cin>>A[i];
	}

	for(int i=1;i<=n;i++){
		if(A[i]<=m){
			B[A[i]]++;
		}
	}

	for(int i=1;i<=n;i++){
		if(A[i]<=m){
			if(B[A[i]]<minB){
				continue;
			}else{
				index = findBWithMinValue();
				if(i!=index){
					B[index]++;
					B[A[i]]--;
				}
				A[i] = index;
			}
		}else{
			index = findBWithMinValue();
			B[index]++;
			A[i] = index;
		}
	}

	for(int i=1;i<=n;i++){
		cout<<A[i];
	}
	

	return 0;
}