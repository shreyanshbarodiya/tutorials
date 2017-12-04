#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,k,t,g;
	string seq;

	cin >> n >> k;
	cin >> seq;

	for(int i=0; i< seq.length(); i++){
		if(seq[i]=='T'){
			t=i;
		}else if(seq[i]=='G'){
			g=i;
		}
	}

	int j=g;

	if(t>g){
		while(j<t){
			j = j+k;
			if(seq[j]=='#'){
				break;
			}
		}

	}else{
		while(j>t){
			j = j-k;
			if(seq[j]=='#'){
				break;
			}
		}
	}

	if(j==t){
		cout<<"YES";
	}else{
		cout<<"NO";
	}

	return 0;
}