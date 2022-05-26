#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define INF 999999

using namespace std;

int N, answer;
int dict[126][126];
int map[126][126];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void initialize(){
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			dict[i][j] = INF;
		}
	}
}

//using priority queue to find answer
void Djikstra(){
	
	priority_queue<pair<int,pair<int, int>>> pq;	//cost, (x,y)
	dict[0][0] = map[0][0];
	pq.push({-map[0][0], {0, 0}});	//set to - so that lowest number can come to top of priority queue
	
	while(!pq.empty()){
		
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		
		pq.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i]; 
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			
			int nCost = cost + map[nx][ny];
			if (nCost < dict[nx][ny]){		//if new path + cost < previous cost of that path, then update
				
				dict[nx][ny] = nCost;	
				pq.push({-nCost, {nx, ny}});
			}
			
		}
		
	}
	answer = dict[N-1][N-1];
}

void reset(){
	memset(dict, INF, sizeof(dict));
	memset(map, 0, sizeof(map));
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int cnt = 0;
	while(1){
		cin >> N;
		
		if (N == 0){
			break;
		}
		
		cnt++;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		
		initialize();
		
		Djikstra();
		
		cout << "Problem " << cnt << ": " << answer << "\n";
		
		reset();
	}
	
}













