#include <cstdio>

int f[]={};
// int fib2(int n){
// 	int i;
// 	f[0] = 0;
// 	if(n>0){
// 		f[1] = 1;
// 		for(i=2;i<=n;i++){
// 			f[i] = f[i-1] + f[i-2];
// 		}
// 	}
// 	return f[n];
// }

int fib2(int n){
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i] = f[i-1]+f[i-2];
	}
	return f[n];
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",fib2(n));
}