#include <iostream>

#define FIRST(i) (isLucky(i,2))? cout << i<< " " : cout << "";
using namespace std;

bool isLucky(int n,int counter){
	if(n<counter){
		return true;
	}
	if(n%counter==0){
		return false;
	}

	return isLucky(n-(n/counter), counter+1);
}

int main(){
	for(int i=1; i<100; i++){
		FIRST(i)
	}
	
}

//cb100
//flat50