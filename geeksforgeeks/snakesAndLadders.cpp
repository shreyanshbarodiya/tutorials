#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct queueEntry{
	int v;
	int d;
}

int minMovesToEnd(int board[], int N){
	queue<queueEntry> q;

	bool visited[N] ;
	for(int i=0; i<N; i++){
		visited[i] = false;
	}

	queueEntry qe = {0,0};
	
	q.push(qe);
	visited[0] = true;

	int V;

	while(!q.empty()){
		qe = q.front();
		V = qe.v;	
		if(V == N-1){
			break;
		}
		q.pop();
		for(int i=V+1; i<=V+6 && i<N; i++){
			if(!visited[i]){
				visited[i] = true;
				queueEntry a;
				a.d = qe.d + 1;
				if(board[i]!=-1){
					a.v = board[i];
				}else{
					a.v = i;
				}
				q.push(a);
			}

		}

	}
	return qe.d;


}

int main(){
	int N;
	int *board = new int[N];

	N = 30;

	for(int i=0; i<N; i++){
		board[i] = -1;
	}

	// ladders
	board[2] = 21;
	board[4] = 7;
	board[10] = 25;
	board[19] = 28;
	
	// Snakes
	board[26] = 0;
	board[20] = 8;
	board[16] = 3;
	board[18] = 6;

	cout << minMovesToEnd(board, N) << endl;

	free(board);
	return 0;
}	