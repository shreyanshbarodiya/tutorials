#include <bits/stdc++.h>
using namespace std;
int main(){
	int long long b,sum=0,a,i,c[100005],d,j,minn;
	cin>>a;

	for(i=1;i<=a;i++){
		cin>>c[i];
		sum+=c[i];
	}

	sort(c+1,c+a+1);
	d=sum;
	sum=sum/a;
	j=d-sum*a;
	for(i=a;i>0;i--,j--){
		if (j==0){
			sum--;
		}
		minn+=max(c[i]-sum-1,0ll);
	}
	cout<<minn<<endl;
}