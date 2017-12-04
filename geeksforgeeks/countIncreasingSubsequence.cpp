#include <iostream>

using namespace std;

long long int increasingSubsequences_nSquare(int arr[], int n){

	long long int cSub[n];

    for (int i = 0; i < n; i++ )
        cSub[i] = 1;


    for (int i = 1; i < n; i++ )
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j])
                cSub[i] += cSub[j];

    long long int result = 0;
    for (int i = 0; i < n; i++ )
          result += cSub[i];

    return result;

}

long long int increasingSubsequences_n(int arr[], int n){
	long long int count[10]={0};

	for(int i=0; i<n; i++){
		for(int j=arr[i]-1; j>=0; j--){
			count[arr[i]]+= count[j];
		}
		count[arr[i]]++;
	}

	long long int result = 0;
    for (int i = 0; i < 10; i++ )
          result += count[i];

    return result;
}

int main(){
	int t,n;
	cin >> t;
	int a[500];

	for(int t0=0; t0<t; t0++){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}

//		cout << increasingSubsequences_nSquare(a,n) << endl;
		cout << increasingSubsequences_n(a,n) << endl;

	}



	return 0;
}