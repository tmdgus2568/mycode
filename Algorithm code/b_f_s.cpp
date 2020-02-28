#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N = 4, W = 16;
int maxprofit = 0;
int numnodes = 1;
vector<pair<float,pair<int, int> > > v;
vector<float> pw;
vector<int> p;
vector<int> w;

/* node 구조체 정의 */
struct node{
    int level;
    int profit;
    int weight;
    float bound;
};

/* bound가 높으면 우선순위가 높다 */
struct compare{
    bool operator()(node one, node two){
        return one.bound < two.bound;
    }
};

/* bound를 계산해주는 함수 */
float bound(node n) {
    int j, k;
    int tw; // 총 weight
    float bound; 
    
    if(n.weight >= W) 
        return 0;
    else {
        bound = (float)n.profit;
        j = n.level+1;
        tw = n.weight;
        while(j <= N && tw + w[j] <= W) { 
            tw = tw + w[j];
            bound = bound + p[j];
            ++j;
        }
        k = j;
        if(k <= N)
            bound = bound + (W - tw) * p[k]/w[k];
        return bound;
    }
}


void best_first_search(){
    node u,v;
    priority_queue<node, vector<node>, compare> pq; 
    v.level=0;
    v.profit=0;
    v.weight=0;
    v.bound=bound(v);
    pq.push(v);
    while(!pq.empty()){ 
        v = pq.top(); 
        pq.pop();
        printf("%d %d\n",v.weight, v.profit);
        if(v.bound > maxprofit){ 
            numnodes += 2; 
            u.level = v.level+1; 
            u.weight = v.weight + w[u.level];
            u.profit = v.profit + p[u.level];
            if(u.weight <= W && u.profit > maxprofit) 
                maxprofit = u.profit;

            u.bound = bound(u);
            if(u.bound > maxprofit && u.weight < W) 
                pq.push(u); 

            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u);
            if(u.bound > maxprofit && u.weight < W) 
                pq.push(u);
            printf("%d %d\n",u.weight, u.profit);
            
        }
        

    }
    
}

int main(){
    p.push_back(0);
    w.push_back(0);
    pw.push_back(0);

    p.push_back(40);
    p.push_back(30);
    p.push_back(50);
    p.push_back(10);

    w.push_back(2);
    w.push_back(5);
    w.push_back(10);
    w.push_back(5);

    pw.push_back(20);
    pw.push_back(6);
    pw.push_back(5);
    pw.push_back(2);

    for(int i=0;i<=N;i++)
        v.push_back(make_pair(pw[i],make_pair(p[i],w[i])));

    sort(v.begin(),v.end());

    best_first_search();
    printf("maxprofit = %d\n",maxprofit);
    printf("numnodes = %d\n",numnodes); 
}
