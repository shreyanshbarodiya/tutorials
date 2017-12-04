#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canBeRead(string w, string s){
	if(s.length()==1){
		for(int i=0; i<w.length(); i++){
			if(w[i]!=s[0]){
				return false;
			}
		}
		return true;
	}else{
		int j=0,i=0;
		while(i<w.length() && j<s.length()){
			if(w[i]==s[j]){
				if(i==w.length()-1){
					return true;
				}else{
					if(w[i]!=w[i+1]){
						j++;
					}					
				}

			}else{
				return false;
			}
			i++;
		}
		return true;
	}
}

int main(){
	string s,w;
	int n;
	cin >> s;
	cin >> n;

	sort(s.begin(),s.end());

	for(int i=0; i<n; i++){
		cin >> w;
		sort(w.begin(),w.end());
		if(canBeRead(w,s)){
			cout << "Yes"<<endl;
		}else{
			cout << "No"<<endl;
		}
	}

	return 0;
}