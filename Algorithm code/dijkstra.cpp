#include <cstdio>
#include <iostream>
#include <algorithm>
#define inf 100000

using namespace std;

int n=5;
int W[6][6]={{0,0,0,0,0,0},
			{0,0,inf,5,7,1},
			{0,8,0,inf,inf,inf},
			{0,inf,3,0,6,inf},
			{0,inf,4,inf,0,inf},
			{0,inf,inf,inf,1,0}};

int vnear;
int Min;
int e;
int touch[6]={};
int length[6]={};
int F[6] = {};
void dijkstra(){

	for(int i=2;i<=n;i++){
		touch[i]=1;
		length[i] = W[1][i];
	}

	for(int i=2;i<=n;i++){
		Min = inf;
		for(int j=2;j<=n;j++){
			if(0<=length[j] && length[j]<Min){
				Min = length[j];
				vnear = j;
			}
		}
		printf("%d\n",vnear);

		for(int j=2;j<=n;j++){
			if(length[vnear]+W[vnear][j]<length[j]){
				length[j] = length[vnear]+W[vnear][j];
				touch[j] = vnear;
			}
		}

		length[vnear] = -1;
	}
}


int main(){
	dijkstra();
	printf("touch : ");
	for(int i=2;i<=n;i++){
		printf("%d ",touch[i]);
	}
	printf("\n");
	printf("length : ");
	for(int i=2;i<=n;i++){
		printf("%d ",length[i]);
	}
	printf("\n");

}