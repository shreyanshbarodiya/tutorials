#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int LCSubstr(string s1, string s2, int l1, int l2){
	int result = 0;
	int LCSuff[l1+1][l2+1];

	for(int i=0; i<=l1; i++){
		for(int j=0; j<=l2; j++){
			if (i == 0 || j == 0){
                LCSuff[i][j] = 0;
			}
			else if (s1[i-1] == s2[j-1]){
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else{
				LCSuff[i][j] = 0;
            } 
		}
	}
	return result;
}

int main(){

	int T;
	cin >> T;
	int l1,l2;
	string s1,s2;

	for(int t=0; t<T; t++){
		cin >> l1 >> l2;
		cin >> s1 >> s2;

		cout << LCSubstr(s1,s2,l1,l2) << endl;

	}

	return 0;
}
