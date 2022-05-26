#include <iostream>
#include <queue>
#include <string.h>

#define INF 90000

using namespace std;

int N, result;
int map[126][126];
int ans[126][126];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void initialize(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			ans[i][j] = INF;	//put INF in ans first, so that we can find min as we move on
		}
	}
	
}

void bfs(){
			
	q.push({0, 0});
	ans[0][0] = map[0][0];

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			
			if (ans[nx][ny] > ans[x][y] + map[nx][ny]){	//what we've found before (at first, it's INF) > current + future value
				ans[nx][ny] = ans[x][y] + map[nx][ny];
				q.push({nx, ny});
			}
		}
	}
	
	result = ans[N-1][N-1];
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int cnt = 0;
	while(1){
		cnt++;
		cin >> N;	
		if (N == 0) break;
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		
		initialize();
		bfs();
				
		cout << "Problem " << cnt << ": " << result << "\n"; 
		
		memset(map, 0, sizeof(map));
	}
	
}


