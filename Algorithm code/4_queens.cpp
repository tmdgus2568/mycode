#include <cstdio>
#include <math.h>
#include <iostream>

using namespace std;
//27개

int n = 4;
int col[5] = {};
int ans = 1;


bool promising(int i){//v가 유망하다면 true, 유망하지 않다면 false
	int k = 1;
	bool swt = true;
	while(k < i && swt){
		if(col[i] == col[k] || abs(col[i]-col[k]) == abs(i-k))
			swt = false;
		k++;
	}
	return swt;
}


void queens(int i){
	// printf("col[%d] : %d\n",i,col[i]);
	for(int x=1;x<=n;x++){
		printf("%d ",col[x]);
	}
	printf("\n");
	if(promising(i)){
		if(i == n){
			printf("-------------------------------------------\nanswer %d : \n",ans);
			for(int a=1;a<=n;a++){
				printf("%d ",col[a]);
			}
			printf("\n-------------------------------------------\n\n");
			ans++;
		}
		else{
			for(int j=1;j<=n;j++){
				col[i+1] = j;
				queens(i+1);
			}
		}
	}
}


int main(){
	queens(0);
}