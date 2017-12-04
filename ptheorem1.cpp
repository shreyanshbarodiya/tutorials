#include <iostream>
using namespace std;
int main()
{
	long long int a;
	cin>>a;
	if(a<=2){
		cout<<-1;
	}else{
		if(a%2 == 1){
			cout<<a*a/2<<" "<<a*a/2+1;
		}else{
			cout<<a*a/4-1<<" "<<a*a/4+1;
		}
		
	}
	
}