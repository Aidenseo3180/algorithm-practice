#include <iostream>
#include <string>

#define endl "\n"
#define MAX 1001

using namespace std;

int M, N;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int y, int x){
	visited[y][x] = true;
		
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		
		if (!visited[ny][nx] && map[ny][nx] == 0){
			visited[ny][nx] = true;
			map[ny][nx] = 2;	//mark as 2 to indicate visited
			dfs(ny,nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	string input;
	for (int i = 0; i < M; i++){
		cin >> input;
		
		//convert string -> char -> int
		for (int j = 0; j < N; j++){
			map[i][j] = input[j] - '0';
		}		
	}

	//start from outer side, so
	for (int j = 0; j < N; j++){
		//0 : electric, 1 : non-electric. When electric, electricity then can connect through
		if (map[0][j] == 0 && !visited[0][j]) dfs(0, j);
	}
	
	for (int j = 0; j < N; j++){
		//if visited inner side
		if (map[M - 1][j] == 2){
			cout << "YES";
			return 0;
		}
	}
	
	cout << "NO";

	return 0;
}










