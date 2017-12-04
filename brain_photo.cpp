#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<vector<char> > photo;
	vector<char> temp;

	char p;

	for(int r = 0; r<n ; r++){
		temp.clear();
		for(int c = 0; c<m ; c++){
			cin>>p;
			temp.push_back(p);
		}

		photo.push_back(temp);
	}

	int x = 1;

	for(int r = 0; r<n ; r++){
		for(int c = 0; c<m ; c++){
			p = photo[r][c];
			if(p == 'C' || p == 'M' || p =='Y'){
				x = 0;
			}
		}
	}

	if(x == 1){
		cout << "#Black&White" << endl;
	}else{
		cout<< "#Color"<<endl;
	}


	return 0;
}
