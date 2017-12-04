#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	int n,x,count,temp=0;
	vector<int> p;
	char s[100];
	char c;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		p.push_back(x);
	}

	for(int i=0; i<n; i++){
		scanf("%99s",s);
		string str(s);
		count = 0;
		for(int j=0; j<99; j++){
			c = s[j];
			if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ){
				count++;
			}
		}
		cout << endl << s << ": " << count << endl;
		if(count<p[i]){
			temp = 1;
			break;
		}
	}

	if(temp == 1){
		cout << "NO";
	}else{
		cout << "YES";
	}
	return 0;
}