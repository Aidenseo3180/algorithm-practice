#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int M, N;
int cnt = 0;
int arr[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

//memorization
//DP[a][b] = c 는 (a,b)부터 (N-1, M-1)까지 총 c개의 경로로 도달할 수 있다 - 라는 뜻 
int DP[501][501];

void Input(){
	
	cin >> M >> N;

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			DP[i][j] = -1;	//set dp's to -1 (bc 0 means there's 0 paths, so 0 will be used, but -1 won't) 
		}
	}
}

int dfs(int x, int y){
	//count + 1 if reaches the end
	if(x == M - 1 && y == N - 1) return 1;
	
	//if we've visited before
	if (DP[x][y] != -1) return DP[x][y];
	
	DP[x][y] = 0;
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
		
		if (arr[nx][ny] < arr[x][y]){
			DP[x][y] = DP[x][y] + dfs(nx, ny);
		}
	}
	return DP[x][y];
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	Input();
	
	cout << dfs(0, 0);
}















