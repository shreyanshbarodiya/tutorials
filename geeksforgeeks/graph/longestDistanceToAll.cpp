#include <iostream>
#include <list>
#include <climits>
#include <stack>

using namespace std;

class AdjListNode{
	public:
		int v;
		int w;
};

class Graph{
	int V;
	list<AdjListNode> *adj;

	public:
		Graph(int _V){
			V = _V;
			adj = new list<AdjListNode>[V];
		}
		void addEdge(int i, int j, int weight){
			AdjListNode a;
			a.v = j;
			a.w = weight;
			adj[i].push_back(a);
		}
		void topoSortUtil(int ver, bool visited[], stack<int> &s){
			visited[ver] = true;
			for(list<AdjListNode>::iterator it= adj[ver].begin(); it!= adj[ver].end(); it++){
				if(!visited[it->v]){
					topoSortUtil(it->v, visited, s);
				}
			}
			s.push(ver);
		}
		void longestPath(int src){
			int *dist = new int[V];

			stack<int> s;
			bool *visited = new bool[V];
			for(int i=0; i<V; i++){
				visited[i] = false;
				dist[i] = INT_MIN;
			}

			dist[src] = 0;

			for(int i=0; i<V; i++){
				if(visited[i] == false){
					topoSortUtil(i, visited, s);
				}
			}

			int curr;
			while(!s.empty()){
				curr = s.top();
				s.pop();

				if(dist[curr]!= INT_MIN){
					for(list<AdjListNode>::iterator it = adj[curr].begin(); it!= adj[curr].end(); it++){
						if(dist[curr] + it->w > dist[it->v] ){
							dist[it->v] = dist[curr] + it->w ;
						}
					}					
				}
			}

			for(int i = 0; i < V; i++){
				(dist[i]==INT_MIN)? cout << "INF " : cout << dist[i] << " " ; 
			}

		}


};

int main(){
Graph g(6);
g.addEdge(0, 1, 5);
g.addEdge(0, 2, 3);
g.addEdge(1, 3, 6);
g.addEdge(1, 2, 2);
g.addEdge(2, 4, 4);
g.addEdge(2, 5, 2);
g.addEdge(2, 3, 7);
g.addEdge(3, 5, 1);
g.addEdge(3, 4, -1);
g.addEdge(4, 5, -2);
int s = 1;
cout << "Following are longest distances from source vertex " << s <<" \n";
g.longestPath(s);
return 0;
}

