#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int kadane(int A[], int n){
    int sum=A[0], maxS=A[0];
    
    for(int i=1; i<n; i++){
        sum = max(sum+A[i], A[i]);
        maxS = max(sum, maxS);
    }
    return maxS;
}

int main() {
	//code
	int T,N;
	int A[101];
	cin >> T;
	
	for(int t=0; t<T; t++){
	    cin >> N;
	    for(int i=0; i<N; i++){
	        cin >> A[i];        
	    }
	    
	    cout << kadane(A,N) << endl;
	    
	}
	
	return 0;
}