#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

#define INF 9999

using namespace std;

int start, V, E;

vector<pair<int,int>> vertex[10001];	//stores info of each node
int d[10001];	//shortest path table

//initialize shortest path table with INF
void initialize(){
	
	for (int i = 0; i < E; i++){
		d[i] = INF;
	}
}

void Djikstra(){
	
	priority_queue<pair<int,int>> pq;
	pq.push({0, start});	//d 값, 현재 정점 (시작이니까 start) 
	d[start] = 0;
	
	while(!pq.empty()){
		
		int cost = -pq.top().first;	//방문한 정점 d 값 
		//top()하면 queue tree에 가장 높은(root)를 가져옴 
		//-하는 이유는 최소합을 구하려고! priority queue는 가장 높은 수가 맨 위에 감. 하지만 -로 하면 가장 낮은 (-1 같이 낮은) 수가 tree의 맨위에 감! 
		
		int cur = pq.top().second;	//현재 방문한 정점 
		pq.pop();
		
		for (int i = 0; i < vertex[cur].size(); i++){	//현재 방문한 정점 주위 조사 
			
			int next = vertex[cur][i].first;		//조사할 다음 정점 
			int next_cost = cost + vertex[cur][i].second;	//현재 정점을 거쳐서 다음 정점을 갈때 비용 
			
			//cout << next << " " << next_cost << " " << d[next] << "\n"; 
			if (next_cost < d[next]){	//기존 비용보다 현재 방문한 정점을 거친 비용이 더 싸면 
				d[next] = next_cost;		//갱신 (shortest path table을 업데이트) 
				pq.push({-next_cost, next});		//pq에 저장 
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E; 	//정점, 간선 
	
	// 모든 간선 정보를 입력받기
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        // from 노드에서 to 노드로 가는 비용이 cost 라는 의미
        
		//양방향 그래프 
		vertex[from].push_back({to, cost});
        vertex[to].push_back({from, cost});
    }
	
	initialize();
	Djikstra();
	
	cout << "result : \n";
	for (int i = 0; i < V; i++){
		if (d[i] == INF){
			cout << "From 0 to " << i << " : INF\n";
		}
		else cout << "From 0 to " << i << " : " << d[i] << "\n";
	}

}

