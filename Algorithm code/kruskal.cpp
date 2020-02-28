#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<pair<int, pair<int, int> > > E; // 가중치,(노드1, 노드2) -> 노드1 과 노드2 를 잇는 이음선은 '가중치'
vector<vector<int> > V; // 서로소 부분 집합
vector<pair<pair<int, int>,int > > F; // MST를 이루는 이음선의 집합 + 가중치(출력을 위해)
int n = 5;


void initial(){ // n개의 서로소 부분 집합을 초기화
	for(int i=1;i<=n;i++){
		vector<int> v;
		v.push_back(i);
		V.push_back(v);
	}
}

int find(int index){ // index가 포함된 집합의 위치 i를 return
	for(int i=0;i<n;i++){
		for(int j=0;j<V[i].size();j++){
			if(V[i][j] == index)
				return i;
		}
	}
	return 0;//서로소 부분집합이기 때문에 여기까지 올 일이 없음
}

void merge(int p, int q){ //p번째에 위치한 집합과 q번째에 위치한 집합을 합친다
	if(p>q){
		for(int i=0;i<V[q].size();i++){
			V[p].push_back(V[q][i]); // q번째에 위치한 집합을 모두 p번째에 위치한 집합에 옮김
		}
		V.erase(V.begin()+q); // q번째에 위치한 집합을 없앰(두 집합을 합쳐서 한 곳에 모은 것과 같다)
	}
	else{
		for(int i=0;i<V[p].size();i++){
			V[q].push_back(V[p][i]);
		}
		V.erase(V.begin()+p);
	}
}


void kruskal(int n){
	int min_point = 0;
	initial();
	while(F.size() < n-1){
		pair<int, int> e;
		e = E[min_point].second; // 아직 점검하지 않은 최소의 가중치를 가진 이음선(두 노드가 저장되어 있음)
		int f = E[min_point].first; // 이어진 두 노드의 가중치
		int i = E[min_point].second.first; // e를 이루는 노드의 번호1
		int j = E[min_point].second.second; // e를 이루는 노드의 번호2
		int p = find(i);
		int q = find(j);

		if(p!=q){ // 같은 집합이 아니라면 
			merge(p,q); 
			F.push_back(make_pair(e,f));
		}
		min_point++; 
		/* 이미 sort한 후였기 때문에 
		바로 다음 index를 확인하면 된다. */
	}
}


int main(){
	E.push_back(make_pair(1,make_pair(1,2)));
	E.push_back(make_pair(2,make_pair(3,5)));
	E.push_back(make_pair(3,make_pair(1,3)));
	E.push_back(make_pair(3,make_pair(2,3)));
	E.push_back(make_pair(4,make_pair(3,4)));
	E.push_back(make_pair(5,make_pair(4,5)));
	E.push_back(make_pair(6,make_pair(2,4)));

	sort(E.begin(),E.end());
	kruskal(n);
	for(int i=0;i<F.size();i++){
		printf("{%d,%d} %d\n",F[i].first.first,F[i].first.second,F[i].second);

	}
}