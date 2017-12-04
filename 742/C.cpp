#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y){
	if(x==y){
		return x;
	}else if(x>y){
		return gcd(x-y,y);
	}else{
		return gcd(x,y-x);
	}
}

int lcm(int x, int y){
	return x*y/gcd(x,y);
}

int lcm_array(vector<int> v){
	int length = v.size();
	int l= v[0];

	for(int i=1; i<length ; i++){
		l = lcm(l, v[i]);
	}
	return l;
}

int main(){
	int n,x;
	cin >> n;
	vector<int> v;
	v.push_back(0);
	bool noCycle = false;
	vector<int> counts;

	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}

	// length of v is n+1 , discard v[0]

	vector<int> v_in(n+1,0);

	for(int i=1; i<=n; i++){
		v_in[v[i]] = i;

	}

	for(int i=1; i<=n; i++){
		if(v_in[i] == 0){
			noCycle = true;
		}
	}

	if(noCycle){
		cout<<-1;
	}else{
		bool visited[n+1] = {false};
		int next,count=0;
		int maxCount=0;

		for(int i=1; i<=n; i++){
			next = v[i];
			count=0;
			if(!visited[i]){
				while(next!=i){
					visited[next]=true;
					next= v[next];
					count++;
				}
			}
			count++;
			if(count%2==0){
				count = count/2;
			}

			if(count>maxCount){
				maxCount = count;
			}
			counts.push_back(count);
			visited[i] = true;
		}

		/*cout << maxCount;*/
		cout << lcm_array(counts);


	}
	



	return 0;
}