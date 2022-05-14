#include <bits/stdc++.h>

using namespace std;

int M, N, K;
int arr[101][101];
int visited[101][101];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> v;
int cnt;

void dfs(int x, int y){
	
	visited[x][y] = 1;

	cnt++;	
	
	for (int a = 0; a < 4; a++){
		int nx = x + dx[a];
		int ny = y + dy[a];
		
		if (0 <= nx && nx < M && 0 <= ny && ny < N){	
			if (arr[nx][ny] == 0 && visited[nx][ny] == 0){
				dfs(nx, ny);
			}
		}
	}
	
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> M >> N >> K;
	
	int x1, x2, y1, y2;

	for (int i = 0; i < K; i++){
		
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int a = x1; a < x2; a++){
			for (int b = y1; b < y2; b++){
				arr[b][a] = 1;	
			}
		}
	}
	
	for (int j = 0; j < N; j++){
		for (int i = M-1; i >= 0; i--){
			if (arr[i][j] == 0 && !visited[i][j]){
				cnt = 0;
				
				//look for 0s in arr
				dfs(i, j);
				
				v.push_back(cnt);
			}
		
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	
	return 0;
}



