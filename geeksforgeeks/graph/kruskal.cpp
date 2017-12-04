#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

class Edge{
	public:
		int src, dest, weight;
};

class Graph{
	public:
		int E, V;
		Edge *edge;
};

Graph* createGraph(int E, int V){
	Graph* g = new Graph;
	g->E = E;
	g->V = V;
	g->edge = new Edge[E];

	return g;
}

// along with path compression
int set_find(int parent[], int i){
	if(parent[i]!=i){
		parent[i] = set_find(parent, parent[i]);
	}
	return parent[i];
}

void set_union(int parent[], int rank[], int i, int j){
	int x = set_find(parent, i);
	int y = set_find(parent, j);

	if(rank[x]>rank[y]){
		parent[y] = x;
	}else if(rank[x]<rank[y]){
		parent[x] = y;
	}else{
		parent[x] = y;
		rank[y] = rank[y] + 1;
	}
}

bool sortEdge(Edge a, Edge b){
	return a.weight<b.weight;
}

void print_MST_with_kruskal(Graph *g){
	int v = g->V;
	int e = g->E;
	Edge *edges = g->edge;
	int parent[v];
	int rank[v];
	int x,y;
	vector<Edge> result;

	for(int i=0; i<v; i++){
		parent[i]=i;
		rank[i]=0;
	}

	sort(edges, edges+e, sortEdge);

	Edge currEdge;

	cout << v << endl << e << endl;

	for(int i=0; i<e; i++){
		currEdge = edges[i];
		x = set_find(parent, currEdge.src);	
		y = set_find(parent, currEdge.dest);	
		if(x==y){
			continue;
		}else{
			result.push_back(currEdge);
			set_union(parent, rank, currEdge.src, currEdge.dest);
		}
	}

	for (int i = 0; i < result.size(); ++i)
		printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

}

int main(){
	
	int V = 4; // Number of vertices in graph
	int E = 5; // Number of edges in graph
	Graph* graph = createGraph(E, V);
	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	graph->edge[0].weight = 10;
	// add edge 0-2
	graph->edge[1].src = 0;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 6;
	// add edge 0-3
	graph->edge[2].src = 0;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 5;
	// add edge 1-3
	graph->edge[3].src = 1;
	graph->edge[3].dest = 3;graph->edge[3].weight = 15;
	// add edge 2-3
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight = 4;

	print_MST_with_kruskal(graph);
	return 0;
}