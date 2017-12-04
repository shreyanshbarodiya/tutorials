#include <iostream>

using namespace std;

int uniqueBSTs(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	int answer = 0;

	for(int i=1; i<=n; i++){
		answer+= uniqueBSTs(i-1)*uniqueBSTs(n-i);
	}
	return answer;

}

int main(){
	int T, n;
	cin >> T;

	for(int t=0; t<T; t++){
		cin >> n;
		cout << uniqueBSTs(n) << endl;
	}



	return 0;
}