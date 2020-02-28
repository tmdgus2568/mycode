#include <cstdio>
#include <iostream>
#include <algorithm>
#define infinity 100000

using namespace std;

int n=4;//전체 노드의 개수이다.
int W[4][4]={{0,7,5,2},
			{8,0,9,infinity},
			{4,infinity,0,7},
			{3,10,infinity,0}}; // 각각 인접한 노드들의 길이를 행렬로 나타냈다.
int D[4][1<<4]={};
int Find[4][1<<4]={};//최적 길이의 경로를 찾는다
/* 각 노드와 노드의 최적 길이를 저장하는 행렬. 
	1<<4는 1 0 0 0 0 으로 각 노드를 나타내려면 최대 1 1 1 1 이므로 
	1 0 0 0 0 을 넘을 순 없다. */

/* v값은 강의노트에서 부분집합A를 비트로 나타낸 것이다. 
	예) 0011이면 부분집합A={v3,v4} */

int tsp(int k, int v){
	if(D[k][v]!=-1)// 이미 확인 했으므로
		return D[k][v];// 있는거 return
	if(v==(1<<n)-1){// 모든 노드를 방문 했다면(마지막 v에 도달했다면) -> 1 1 1 1
		if(W[k][0]!=0)// v1과 바로 연결된 vk의 길이를 더한다 (순환이므로 마지막에 v1->vk를 더한다.) 
			return W[k][0];
		return infinity;// v1과 v1은 필요 없으므로 inf로 설정한다.
	}

	/* 
		D[k][v]==-1(아직 한번도 확인한 적 없으며) 
		&& v!=(1<<n)-1(아직 모든 노드를 다 돌지 않았다) 
												*/

	D[k][v]=infinity;// 가장 작은 것을 찾고, 확인 했다는 증거로 -1을 없애기 위해 inf 대입
	for(int i=0;i<n;i++){
		if(!((v&(1<<i))||W[k][i]==0)){
			/* 예) v가 0011이고 i가 1일 때 1<<i는 10이다
				이때, &연산을 해도 그대로이므로(비트마스크로 막혀있으므로), 또한 W[k][i]==0이면 자기 자신의 노드이므로
				이 if문을 통과할 수 없다. */
			if(D[k][v] > W[k][i]+tsp(i,v|(1<<i)))// D[k][v]가 바뀌었다는 뜻이므로 경로도 바뀐다
				Find[k][v]=i;
			D[k][v] = min(D[k][v], W[k][i]+tsp(i,v|(1<<i)));
			
			/* 예) v가 0011이고 i가 2일 때 1<<i는 100이다
				따라서 인접한 vk->vi에 vi->v(부분집합A에서 vi와 v1을 뺀 나머지 노드)를 더한다*/
		}
	}
	return D[k][v];// 최종적으로 가장 최적의 순환 길이를 출력한다.
}

void find_shortest_route(int k, int v){
	if(k!=-1){// k==-1이면 한번도 건들지 않은 노드 이므로 우리가 찾는 경로와 관련이 없기 때문에 아무것도 출력하지 않는다.
		printf("v%d ",k+1);// 노드 번호라 +1을 해준다
		find_shortest_route(Find[k][v], v|1<<(Find[k][v]));
		/* Find배열은 연결된 다음 노드를 찾을 수 있으므로 
			재귀를 통해 배열의 원소를 타고타고 들어간다 */

	}
}

int main(){
	memset(D,-1,sizeof(D));
	memset(Find,-1,sizeof(Find));
	/* -1로 초기화 후 지날 때 마다 -1을 없애(다른 값을 넣어) 지나간
	 적이 있다는 것을 확인할 수 있다. */
	printf("Shortest Length : %d\n",tsp(0,1));
	printf("Shortest Route : ");
	find_shortest_route(0,1);
}
