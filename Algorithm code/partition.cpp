#include <cstdio>

int s[12]={15,22,13,27,12,10,102,20,25,32,97,1};
void partition(int low, int high, int* p);
void quicksort(int low, int high);

// void partition(int low, int high, int* p){
// 	int pivot = s[low];
// 	int j = low;
// 	for(int i=low+1;i<=high;i++){
// 		if(s[i]<pivot){
// 			j++;
// 			int a = s[j];
// 			s[j] = s[i];
// 			s[i] = a;
// 		}
// 	}
// 	int b = s[low];
// 	s[low] = s[j];
// 	s[j] = b;
// }

// void quicksort(int low, int high){
// 	int store = s[low];
// 	if(high > low){
// 		partition(low, high, s);
// 		for(int i=0;i<high;i++){
// 			if(s[i]==store){
// 				quicksort(low,i-1);
// 				quicksort(i+1,high);
// 				break;
// 			}
// 		}
// 	}
// }


void partition(int low, int high, int* p){
	int pivot = s[low];
	int j = low+1;

	for(int i=low+1;i<=high;i++){
		if(S[i]<pivot)
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
			j++;
			*p++;

	}


}

void quicksort(int low, int high){

}

int main(){
	for(int i=0;i<12;i++)
		printf("s[%2d] : %3d\n",i,s[i]);
	quicksort(0,sizeof(s)/sizeof(s[0])-1);
	printf("\n\n");

	for(int i=0;i<12;i++)
		printf("s[%2d] : %3d\n",i,s[i]);


}