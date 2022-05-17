#include <iostream>
#include <string.h>

using namespace std;

int N;
char arr[101][101];
bool visited[101][101];
int cnt = 0;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int startX, int startY){
	visited[startX][startY] = true;
		
	for (int i = 0; i < 4; i++){
		int nx = startX + dx[i];
		int ny = startY + dy[i];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (!visited[nx][ny] && (arr[nx][ny] == arr[startX][startY])){
			dfs(nx, ny);
			
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
		}
	}
	
	//normal
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!visited[i][j]){
				dfs(i, j);
				cnt++;
			}	
		}
	}
	
	cout << cnt << " ";
	
	cnt = 0;
	memset(visited, false, sizeof(visited));

	//abnormal
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (arr[i][j] == 'G'){
				arr[i][j] = 'R';
			}
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!visited[i][j]){
				dfs(i, j);
				cnt++;
			}	
		}
	}

	cout << cnt;

	return 0;	
}



















