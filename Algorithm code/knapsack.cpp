#include <cstdio>

int W = 5;
int n = 4;
int P[5][6]={};
int I[5][2]={{},{2,3},{3,4},{4,5},{5,6}};

void knapsack(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(I[i][0]<=j){
				if(I[i][1]+P[i-1][j-I[i][0]] > P[i-1][j]){
					P[i][j] = I[i][1]+P[i-1][j-I[i][0]];
				}
				else{
					P[i][j] = P[i-1][j];
				}
			}
			else{
				P[i][j] = P[i-1][j];
			}
			
		}
	}
}


int main(){
	knapsack();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			printf("%d ",P[i][j]);
		}
		printf("\n");
	}
}