#include <cstdio>
#include <algorithm>
#define infinity 10000

using namespace std;

int W[6][6]={{},
			{0,0,1,infinity,1,5},
			{0,9,0,3,2,infinity},
			{0,infinity,infinity,0,4,infinity},
			{0,infinity,infinity,2,0,3},
			{0,3,infinity,infinity,infinity,0}};
int D[6][6]={};
int P[6][6]={};

// void floyd2(int n){
// 	for(int i=1;i<n;i++){
// 		for(int j=1;j<n;j++){
// 			D[i][j] = W[i][j];
// 		}
// 	}
// 	for(int k=1;k<n;k++){
// 		for(int i=1;i<n;i++){
// 			for(int j=1;j<n;j++){
// 				if(D[i][k]+D[k][j]<D[i][j]){
// 					P[i][j]=k;
// 					D[i][j]=D[i][k]+D[k][j];
// 				}
// 			}
// 		}
// 	}
// }

void floyd2(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			D[i][j] = W[i][j];		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(D[i][j]>D[i][k]+D[k][j]){
					P[i][j] = k;
					D[i][j] = D[i][k]+D[k][j];				}

			}
		}
	}
}
void path(int q,r){
	if(P[q][r]!=0)
		path(q,P[q][r])
		printf("v%d\n",P[q][r]);
		path(P[q][r],r)
}

int main(){
	floyd2(6);
	// for(int i=1;i<7;i++){
	// 	for(int j=1;j<7;j++)
	// 		printf("%d ",D[i][j]);
	// 	printf("\n");
	// }
	// for(int i=1;i<7;i++){
	// 	for(int j=1;j<7;j++)
	// 		printf("%d ",D[i][j]);
	// 	printf("\n");
	// }

	for(int i=1;i<6;i++){
		for(int j=1;j<6;j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}
	printf("\n");
	for(int i=1;i<6;i++){
		for(int j=1;j<6;j++){
			printf("%d ",P[i][j]);
		}
		printf("\n");
	}



}