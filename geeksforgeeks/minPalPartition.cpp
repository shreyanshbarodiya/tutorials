#include <iostream>
#include <string>
#include <climits>

using namespace std;

bool isPalindrome(string s, int i, int j){
	if(i==j || i>j){
		return true;
	}
	if(s[i]==s[j]){
		return isPalindrome(s,i+1,j-1);
	}
	return false;
}

int minPartitions(string s, int i, int j){

	

	if(i==j){
		return 0;
	}
	if(isPalindrome(s, i, j)){
		return 0;
	}

	int answer1, answer2;
	int result = INT_MAX ;
	for(int k=i; k<j; k++){
		answer1 = minPartitions(s, i, k); 
		answer2 = minPartitions(s, k+1, j); 
		if(answer1+answer2+1 < result){
			result = answer1+answer2+1;
		}	
	}

	return result;
}

int main(){
	string s;
	cin >> s;

	cout << minPartitions(s, 0 , s.length()-1) << endl;

	return 0;
}