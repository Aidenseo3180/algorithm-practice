#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[300][300];

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

bool visited[300][300];	//for bfs

int dx[] = { 1, -1, 0,0 };
int dy[] = { 0, 0, 1, -1 };

void BFS(int i, int j) {
	queue <pair<int, int >> q;
	q.push({ i,j });
	visited[i][j] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			//if out of scope
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;

			//if alreay visited
			if (visited[ny][nx]) continue;

			if (map[ny][nx] == 0) { //if next location is water
				map[y][x] = (map[y][x] == 0) ? 0 : map[y][x] - 1; //if current location is water, set to 0, if not (meaning ice), -1 from ice.
				//map[y][x] = max(0, map[y][x] - 1);	//nevere go below 0
			}
			else { //if Ice
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

int Solve() {
	int ans = 0;
	int ice = 0;
	
	//same as while loop with ans++ everytime
	for ( ; ; ans++) {
		ice = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//if ice exists AND hans't visited
				if (map[i][j] != 0 && visited[i][j] == false) {
					BFS(i, j);
					ice++; //number of ice chunks
				}
			}
		}
		if (ice >= 2) return ans;
		if (ice == 0) break;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

int main() {
	input();
	printf("%d\n", Solve());
}


/* This works, but is not taken as answer (probably because of x and y of dfs. I think it should be flipped to y, x in parameters

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

#define endl "\n"

using namespace std;

int N, M, year = 0;
int ice[301][301];
queue<pair<int,int>> q;
int visited[301][301];
int size;
int cnt = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

//dfs
void dfs(int x, int y){
	
	visited[x][y] = 1;
	
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];	
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		
		if (!visited[nx][ny]){
			//if ice exists
			if (ice[nx][ny] != 0){
				
				dfs(nx, ny);
				
			}
			//if it's water
			else{
				ice[x][y] -= 1;	
				
				if (ice[x][y] < 0) ice[x][y] = 0;
				
			}	
		}
	}
}

void draw(){

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M;j++){
			cout << ice[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;

}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	int	iceExist = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> ice[i][j];
			
			if (ice[i][j] != 0){
				iceExist = 1;
			}
		}
	}
	
	//if ice doesn't exist
	if (iceExist == 0){
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (ice[i][j] != 0 && !visited[i][j]){
				dfs(i, j);
				memset(visited, 0, sizeof(visited));
				draw();
				year++;
				cnt++;
				
				if (cnt >= 2){
					cout << year;
					return 0;
				}
				if (cnt == 0){
					cout << 0;
					return 0;
				}
			}
			
		}
		cnt = 0;
	}

}

*/









