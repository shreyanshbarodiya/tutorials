#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	int n, n1, n2, x;
	cin >> n >> n1 >> n2;

	vector<int> wealth;

	for(int i=0; i<n ;i++){
		cin >> x;
		wealth.push_back(x);
	} 

	sort(wealth.begin(), wealth.end());
	reverse(wealth.begin(),wealth.end());

	float sum1=0, sum2=0;
	int ma = (n1>n2) ? n1 : n2;
	int mi = (n1<n2) ? n1 : n2; 

	for(int i=0; i<ma+mi ;i++){
		if(i<mi){
			sum1 += wealth[i];
		}else{
			sum2 += wealth[i];
		}
	} 

	printf("%0.8f",sum1/mi + sum2/ma);

	return 0;
}