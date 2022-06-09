#include <iostream>
#include <queue>

#define endl "\n"
#define MAX 1000

typedef long long ll;

using namespace std;

int N, M;
int map[MAX][MAX] = {0,};		//map w/ values
int visited[MAX][MAX] = {0,};
ll count[MAX][MAX] = {0,};		//count over time

queue<pair<int,int>> q;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int startX, int startY){
	
	q.push({startX, startY});
	visited[startX][startY] = 1;
	count[startX][startY] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;	
		q.pop();
		
		for (int i = 0; i < 4; i++){
			
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			
			if (!visited[nx][ny] && map[nx][ny] == 1){
				visited[nx][ny] = 1;
				q.push({nx, ny});
				count[nx][ny] = count[x][y] + 1;
			}	
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	int sX, sY;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 2){
				sX = i;
				sY = j;
			}
		}
	}

	bfs(sX, sY);
	
	//label as -1 if..
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//if map is 1 but count is 0, make count[i][j] as -1
			if (map[i][j] == 1 && count[i][j] == false){
				count[i][j] = -1;
			}
		}
	}
	
	//print
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			
			cout << count[i][j] << " ";
		}
		cout << endl;
	}
}
















