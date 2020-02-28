#include <cstdio>
#include <iostream>

int ans[]={};
int U[]={};
int V[]={};


void merge(int h, int m, int *U, int *V){
	int i=0;
	int j=0;
	int k=0;
	while(i<=h && j<=m){
		if(U[i]<V[i]){
			ans[k]=U[i];
			i++;
		}
		else{
			ans[k]=V[j];
			j++;
		}
		k++;
	}
	while(i<h)
		S[k++]=U[i++];
	while(j<m)
		S[k++]=V[j++];
}


void divide(int n, int *S){

	for(int i=0;i<n/2;i++){
		U[i]=S[i];
	}
	for(int i=n/2;i<n;i++){
		V[i]=S[i];
	}
}



void MergeSort(int n, int *S){
	int h,m,i,*U,*V
	h = n/2;
	m = n-h;

	if(n>1){
		U = (int*)malloc(h*sizeof(int))
		V = (int*)malloc(m*sizeof(int))
		for(i=0;i<h;i++){
			U[i] = S[i];
		}
		for(i=h;i<n;i++){
			V[i-h] = S[i];
		}
		MergeSort(h,U);
		MergeSort(m,V);

		free(U);
		free(V);
	}


}


void merge(int h, int m, int *U, int *V){
	int i,j,k=0;
	while(i<h&&j<m)
		if(U[i]<V[j]){
			S[k]=U[i]
			i++
			k++
		}
		else
			S[]

	if(i<h)
		S[k]
}


void divide(int n, int *S){

	for(int i=0;i<n/2;i++){
		U[i]=S[i];
	}
	for(int i=n/2;i<n;i++){
		V[i]=S[i];
	}
}



void MergeSort(int n, int *S){
	int h,m,i,*U,*V



}

int main(){
	int S[] = {2,3,1,9,15,13,12,17};
	int i, numberOfElements;
	numberOfElements = sizeof(S)/sizeof(S[0]);
	MergeSort(numberOfElements,S);

	for(i=0;i<numberOfElements;i++){
		printf("%d ",S[i]);
	}
}