#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

string decToBin(int i){
	string binString;
	while(i != 0){
		binString += (char) (i%2 + 48);
		i=i/2;
	}
	reverse(binString.begin(),binString.end());
	return binString;
}

bool setBitsEquals(int i, int m){
	string binString = decToBin(i);
	int j=0;
	int setCount=0;
	while(j<binString.length()){
		if(binString[j]=='1'){
			setCount++;
		}
		j++;
	}
	if(setCount==m){
		return true;
	}else{
		return false;
	}
}

int sumSetBits(int n, int m){
	int maximum = pow(2,n) - 1;
	int sum=0;
	for(int i=0; i<=maximum; i++){
		if(setBitsEquals(i,m)){
			//cout <<i << endl;
			sum+=i;
		}
	}
	return sum;
}


int main(){
	cout << sumSetBits(31,1)<<endl;
	return 0;
}