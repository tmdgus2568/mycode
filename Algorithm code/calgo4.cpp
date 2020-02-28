#include <cstdio>

int S[]={1,2,3,4,5,6,7};
int n = 7;
int x;

// int location(int low, int high){
// 	int mid;

// 	if(low>high)
// 		return 0;
// 	else{
// 		mid = (low+high)/2;
// 		if(x == S[mid])
// 			return mid;
// 		else if(x < S[mid])
// 			return location(low,mid-1);
// 		else
// 			return location(mid+1,high);
// 	}
// }


int location(int low, int high){//이분검색알고리즘
	if(low>high)
		return 0;
	else{
		int mid = (low+high)/2;
		if(x<mid)
			return location(low,mid-1);
		else
			return location(mid+1,high);
	}

}



int main(){
	scanf("%d",&x);
	int locationout = location(1,n);
	printf("%d",locationout); 
}