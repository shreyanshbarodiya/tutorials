#include <iostream>
#include <list>

using namespace std;
	
class Graph{
	private:
		int V;
		list<int> *adj;
		void dfsUtil(int i, bool visited[]){
			if(visited[i]){
				return;
			}

			visited[i] = true;
			cout << i << " ";

			for(list<int>::iterator j=adj[i].begin(); j!= adj[i].end(); j++){
				dfsUtil(*j, visited);
			}
		}
	public:
		Graph(int v){
			V=v;
			adj = new list<int>[v];
		}	
		
		void addEdge(int i, int j){
			adj[i].push_back(j);
		}

		void dfs(){
			bool *visited = new bool[V];

			for(int i=0; i<V; i++){
				visited[i] = false;
			}

			for(int i=0; i<V; i++){
				dfsUtil(i, visited);
			}
		}

};	

int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,4);

	g.dfs();
	return 0;
}