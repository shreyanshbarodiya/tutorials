#include <iostream>
#include <list>

using namespace std;

/*class Node{
	public:
		int number;
		int colour;
		list<Node*> children;

		void addEdge(){

		}
};

class Graph{
	public:
		int V;
		Node* root;
};

*/

int colourOfTree(int node, int colour[], list<int> edges[]){
	
}

bool sameColourSubtrees(int node, int colour[], list<int> edges[]){
	for(list<int>::iterator it = edges[node].begin(); it!= edges[node].end(); it++){
		if(colourOfTree(*it, colour, edges)!=colour[node]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	list<int> * edges = new list<int>[n+1];
	int * colour = new int[n+1];

	int l,r;
	for(int i=0; i<n-1; i++){
		cin >> l >> r;
		edges[l].push_back(r);
		edges[r].push_back(l);
	}

	for(int i=1; i<=n; i++){
		cin >> l;
		colour[i] = l;
	}

	bool inThisIter = true;
	bool found = false;
	int root = 0;

	for(int i=1; i<=n; i++){
		for(list<int>::iterator it = edges[i].begin(); it!=edges[i].end(); it++){
			if(!sameColourSubtrees(*it,colour,edges)){
				inThisIter = false;
				break;
			}
		}
		if(inThisIter){
			found=true;
			root = i;
			break;
		}
	}

	if(found){
		cout<< "YES" << endl << i << endl;
	}
	
	return 0;
}