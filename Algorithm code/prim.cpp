#include <cstdio>
#include <iostream>
#include <algorithm>
#define inf 100000

using namespace std;


int vnear=0;
int n=5;
int Y[6]={};
int nearset[6]={};
int dist[6]={};
int W[6][6]={{0,0,0,0,0,0},
			{0,0,1,3,inf,inf},
			{0,1,0,3,6,inf},
			{0,3,3,0,4,2},
			{0,inf,6,4,0,5},
			{0,inf,inf,2,5,0}};


void prim(){
	for(int i=2;i<=n;i++){
		nearset[i] = 1;
		dist[i] = W[1][i];
	}
	Y[1]=1;
	int cnt=2;

	for(int j=0;j<n-1;j++){
		int Min= inf;

		for(int i=2;i<=n;i++){
			if(dist[i]>=0 && dist[i]<=Min){
				Min=dist[i];
				vnear=i;
			}
		}
		Y[cnt]=vnear;
		cnt++;
		dist[vnear]=-1;
		for(int i=2;i<=n;i++){
			if(W[i][vnear] < dist[i]){
				dist[i] = W[i][vnear];
				nearset[i] = vnear;
			}
		}
	}
}

int main(){
	prim();
	printf("nearset : \n");
	for(int i=2;i<=n;i++){
		printf("%d ",nearset[i]);
	}
	printf("\ndistance : \n");
		for(int i=2;i<=n;i++){
		printf("%d ",dist[i]);
	}
	printf("\nY = {");
	for(int i=1;i<=n;i++){
		printf("v%d ",Y[i]);
	}
	printf("}\n");

}