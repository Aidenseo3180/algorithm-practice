#include <bits/stdc++.h>

#define INF 999999999

using namespace std;

int start, goal;
vector<pair<int,int>> vec[1001];
int dist[1001];	//최소값 테이블 

void dijkstra(){
	
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;	//자기자신한테 가는 비용 = 0 	
	pq.push({0, start});	//초기 비용, 시작점 
	
	while(!pq.empty()){
		int cost = -1 * pq.top().first; 	//현재까지 start에서 cur 정점까지 가는 cost
		int cur = pq.top().second;
		pq.pop();
		
		//과거에 pq에 넣어둔 최단거리가 최근 갱신한 최단거리보다 클 경우, (이미 dist가 최소면) 
		if (dist[cur] < cost) continue;
		
		for (int i = 0; i < vec[cur].size(); i++){
			
			int next = vec[cur][i].first;
			int nCost = cost + vec[cur][i].second;
			
			if (nCost < dist[next]){
				dist[next] = nCost;
				pq.push({-1 * nCost, next});
			}
		}		
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N, M;
	
	cin >> N;	//vertex
	cin >> M;	//edges
	
	while(M--){
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});	//a -> b, c = cost
	}
	cin >> start >> goal;
	
	fill_n(dist, 1001, INF);
	
	dijkstra();
	
	cout << dist[goal];
	
	return 0;
}















