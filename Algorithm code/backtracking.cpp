#include <cstdio>

using namespace std;

int M[6][6] = {{0,0,0,0,0,0},{0,0,1,1,0,0},{0,0,0,0,1,1},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0}};
int visit[6][6] = {};
int n=5;

void depth_first_tree_search(int v){
	printf("v : %d\n",v);
	for(int u=1;u<=n;u++){
		if(visit[v][u] != 0){
			visit[v][u] = 0;
			visit[u][v] = 0;
			depth_first_tree_search(u);

		}
	}

}

int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			visit[i][j]=M[i][j];
		}
	}
	depth_first_tree_search(1);

}