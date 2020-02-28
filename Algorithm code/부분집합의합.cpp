#include <cstdio>

using namespace std;

int n = 4;
int w[4]={3,4,5,6};
bool include[100] = {};
int W = 13;

bool promising(int i, int weight, int total){
	return (weight+total>=W)&&(weight==W||weight+w[i+1]<=W);
}

void SumOfSubsets(int i, int weight, int total){//3,4,6
	if(promising(i,weight,total)){
		if(weight == W){
			for(int j=0;j<n;j++){
				if(include[j]==true)
					printf("%d\n",w[j]);
			}

		}
		else{
			include[i+1] = true;
			// printf("%d\n",weight+w[i+1]);
			SumOfSubsets(i+1, weight+w[i+1], total-w[i+1]);//w[i+1]추가
			include[i+1] = false;
			// printf("%d\n",weight);
			SumOfSubsets(i+1, weight, total-w[i+1]);//w[i+1] 추가하지 않는다
		}
	}
}




int main(){
	SumOfSubsets(-1,0,18);

}