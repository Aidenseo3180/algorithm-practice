#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
string map[1002];

int cnt_fire[1002][1002];
int cnt_char[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	queue<pair<int,int>> qc;	//for character
	queue<pair<int,int>> qf;	//for fire

	cin >> M >> N;
	
	for (int i = 0; i < M; i++){
		cin >> map[i];
	}

	//initialize cnt_fire and cnt_char to -1
	for (int i = 0; i < M; i++){
		fill(cnt_fire[i], cnt_fire[i] + N, -1);
		fill(cnt_char[i], cnt_char[i] + N, -1);
	}

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 'J'){
				qc.push({i, j});
				cnt_char[i][j] = 0;
			}
			if (map[i][j] == 'F'){
				qf.push({i, j});
				cnt_fire[i][j] = 0;
			}
		}
	}
	
	
	//fire BFS
	//how the fire would spread
	while(!qf.empty()){
		int x = qf.front().first;
		int y = qf.front().second;	
		
		qf.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			
			if (map[nx][ny] != '#' && cnt_fire[nx][ny] == -1){
				cnt_fire[nx][ny] = cnt_fire[x][y] + 1;
				qf.push({nx, ny});
			}
		}
	}

	//char BFS
	while(!qc.empty()){
		
		int x = qc.front().first;
		int y = qc.front().second;
		qc.pop();

		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//if character manages to get out of maze
			if (nx < 0 || ny < 0 || nx >= M || ny >= N){
				cout << cnt_char[x][y] + 1;
				return 0;
			}

			if (map[nx][ny] == '#' || cnt_char[nx][ny] >= 0) continue;
			
			//if fire BFS is faster than char BFS & have visited,
			//opposite : cnt_char[nx][ny] + 1 < cnt_fire[nx][ny] 	<- + 1 bc we increment cnt by 1 as we move forward (since moving forward, +1 on cnt[x][y])
			if (cnt_fire[nx][ny] <= cnt_char[x][y] + 1 && cnt_fire[nx][ny] != -1) continue;
						
			cnt_char[nx][ny] = cnt_char[x][y] + 1;
			qc.push({nx,ny});
		}
	}	

	//if above didn't reach the end
	cout << "IMPOSSIBLE";
	return 0;
}
















