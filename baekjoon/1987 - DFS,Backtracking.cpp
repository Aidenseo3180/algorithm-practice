#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"

using namespace std;

char arr[21][21];
int visited[26];
int R, C, ans = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bigger(int a, int b){
	
	return (a > b ? a : b);
}

void dfs(int x, int y, int cnt){
	
	ans = bigger(ans, cnt);	//save result that's bigger
		
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

		if (visited[arr[nx][ny] - 'A'] == false){
			visited[arr[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			visited[arr[nx][ny] - 'A'] = false;	//backtracking
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> arr[i][j];
		}
	}
	
	visited[arr[0][0] - 'A'] = true;	//arr[0][0] - 'A' gives us index of visited (int).
	
	dfs(0, 0, 1);
	
	cout << ans;
}














