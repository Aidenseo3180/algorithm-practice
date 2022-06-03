#include <iostream>

#define endl "\n"

using namespace std;

char arr[251][251];
int R, C;
bool visited[251][251];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int wolf, sheep;

int sum[2] = {0, 0};

void dfs(int y, int x){
	visited[y][x] = true;
	
	if (arr[y][x] == 'v') wolf++;	//since we check places without '#' from for loop in main, chheck wolf/sheep
	if (arr[y][x] == 'o') sheep++;
		
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (nx < 0 || ny < 0 || nx >= C || ny >= R) continue;
		
		if (!visited[ny][nx] && arr[ny][nx] != '#'){
			
			dfs(ny, nx);
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			//if not wall && haven't visited
			if (arr[i][j] != '#' && !visited[i][j]){
				wolf = sheep = 0;
				dfs(i, j);
				
				if (sheep > wolf){
					sum[0] += sheep;
				}
				else{
					sum[1] += wolf;
				}
				
			}
		}
	}
	
	cout << sum[0] << " " << sum[1];
	
}










