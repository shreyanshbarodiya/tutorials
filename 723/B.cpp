#include <iostream>
#include <string>

using namespace std;	
int main(){
	int n;
	string s;
	cin >> n >> s;
	bool inPar=false;
	char c;
	int curr=0,maxO=0;
	int nIns=0;

	for(int i=0; i<n; i++){
		c = s[i];
		if(c == '('){
			if(curr>maxO){
				maxO=curr;
				curr=0;
			}
			inPar=true;
		}else if(c == ')'){
			if(s[i-1]!='(' && s[i-1]!='_'){
					nIns++;
			}
			curr=0;
			inPar=false;
		}else if(c == '_'){
			if(curr>maxO && inPar==false){
				maxO=curr;
				curr=0;
		//		cout << maxO<<endl;
			}else if(inPar==true){
				if(s[i-1]!='(' && s[i-1]!='_'){
					nIns++;
				}
			}
			curr=0;
		}else{
			if(inPar==false){
				curr++;
			}
		}
	}

	if(inPar==false){
		if(curr>maxO){
			maxO=curr;
		}
		//cout<<maxO<<endl;
	}

	cout << maxO << " " << nIns<<endl;

	return 0;
}