#include <iostream>
#include <list>

using namespace std;
	
class Graph{
	private:
		int V;
		list<int> *adj;
		bool dfsUtil_detectCycle(int v, bool visited[], bool recStack[]){
			if(visited[v] == false){
				visited[v] = true;
				recStack[v] = true;
				for(list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++){
					if ( !visited[*it] && dfsUtil_detectCycle(*it, visited, recStack) )
						return true;
					else if (recStack[*it])
						return true;
				}
			}

			recStack[v] = false; 
			return false;
		}
	public:
		Graph(int v){
			V=v;
			adj = new list<int>[v];
		}	
		
		void addEdge(int i, int j){
			adj[i].push_back(j);
		}

		bool dfs_detectCycle(){
			bool *visited = new bool[V];
			bool *recStack = new bool[V];

			for(int i=0; i<V; i++){
				visited[i] = false;
				recStack[i] = false;
			}

			for(int i=0; i<V; i++){
				if(dfsUtil_detectCycle(i, visited, recStack)){
					return true;
				}
			}
			return false;
		}

};	

int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(3,0);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);

	cout << (g.dfs_detectCycle() ) ;//<< endl;
	return 0;
}