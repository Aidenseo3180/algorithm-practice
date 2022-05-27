#include <bits/stdc++.h>

#define INF 999999999

using namespace std;

int start, goal;
vector<pair<int,int>> vec[1001];
int dist[1001];	//�ּҰ� ���̺� 

void dijkstra(){
	
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;	//�ڱ��ڽ����� ���� ��� = 0 	
	pq.push({0, start});	//�ʱ� ���, ������ 
	
	while(!pq.empty()){
		int cost = -1 * pq.top().first; 	//������� start���� cur �������� ���� cost
		int cur = pq.top().second;
		pq.pop();
		
		//���ſ� pq�� �־�� �ִܰŸ��� �ֱ� ������ �ִܰŸ����� Ŭ ���, (�̹� dist�� �ּҸ�) 
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















