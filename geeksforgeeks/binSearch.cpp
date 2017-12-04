#include <iostream>

using namespace std;

bool binSearch(int A[], int start, int end, int x){
	int mid = start + (end-start)/2;
	if(start==end){
		return false;
	}

	if(A[mid]==x){
		return true;
	}

	if(A[mid]<x){
		return binSearch(A, mid, end, x);
	}else{
		return binSearch(A, start, mid, x);
	}
}

int main(){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};

	if(binSearch(A, 0, 9, 1)){
		cout<< "Yes" << endl;
	}else{
		cout<<"No"<<endl;
	}

	return 0;
}