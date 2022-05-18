#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char arr[51][51];
int visited[51][51];
int cnt = 0;

int vertical[2][2] = {{1, 0},{-1, 0}};	//y, x
int horizontal[2][2] = {{0, 1}, {0, -1}};

void search(int x, int y, char c){
	visited[x][y] = 1;
	
	if (c == '-'){
		for (int i = 0; i < 2; i++){
			int nx = x + horizontal[i][0];
			int ny = y + horizontal[i][1];
			
			if (nx < 0 || ny < 0 || nx >= N && ny >= M) continue;
			
			if (!visited[nx][ny] && arr[nx][ny] == '-'){
				search(nx, ny, arr[nx][ny]);
			}
		}
	}
	else if (c == '|'){
		for (int i = 0; i < 2; i++){
			int nx = x + vertical[i][0];
			int ny = y + vertical[i][1];
			
			if (nx < 0 || ny < 0 || nx >= N && ny >= M) continue;
			
			if (!visited[nx][ny] && arr[nx][ny] == '|'){
				search(nx, ny, arr[nx][ny]);
			}
		}
	}
	
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;	//N : vertical, M : horizontal
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (!visited[i][j]){
				search(i, j, arr[i][j]);
				cnt++;
			}
		}
	}

	cout << cnt;
}

	
















