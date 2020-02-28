#include <cstdio>
#include <algorithm>

using namespace std;

int B[][100]={};
// int bin2(int n, int k){

// 	for(int i=0;i<=n;i++){
// 		for(int j=0;j<=min(i,k);j++)
// 			B[i][j] = (i==0 || j==0) ? 1 : B[i-1][j-1]+B[i-1][j];

// 	}
// 	return B[n][k];
// }
int bin2(int n, int k){

	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(k,i);j++){
			if(i==0 || j==0)
				return 1;
			else
				B[i][j] = B[i-1][j-1]+B[i-1][j];
		}
	}
	return B[n][k]
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",bin2(a,b));
}