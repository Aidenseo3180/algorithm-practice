#include <iostream>
#include <queue>
#include <vector>

#define INF 999999

using namespace std;

int V,E,K;
int d[20001];
vector<pair<int, int>> vertex[20001];
priority_queue<pair<int,int>> pq;

void initialize(){
	for (int i = 1; i <= V; i++){
		d[i] = INF;
	}
}

void djikstra(){
	pq.push({0, K});	//d value , current index
	d[K] = 0;
	
	while(!pq.empty()){
		
		int cost = -pq.top().first;	//the path cost
		int cur = pq.top().second;	//current index
		
		pq.pop();
		
		for (int i = 0; i < vertex[cur].size(); i++){	//check all the connected nodes
			
			int next = vertex[cur][i].first;		//next node
			int nCost = cost + vertex[cur][i].second;	// cost until current node + cost of next node
			
			//cout << nCost << " < " << d[i] << " : " << " " << cur << " - " << next << "\n";
			if (nCost < d[next]){	//if previous cost until next node is lower, update the min value
				d[next] = nCost;
				pq.push({-nCost, next});
			}	
		}
	}
	
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> V >> E;
	cin >> K;
	
	int u, v, w;
	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;			//u - > v, w = cost
		vertex[u].push_back({v,w});
	}
	
	initialize();
	djikstra();
	
	for (int i = 1; i <= V; i++){
		if (d[i] == INF)
			cout << "INF\n";
		else 
			cout << d[i] << "\n";
	}
		
}


