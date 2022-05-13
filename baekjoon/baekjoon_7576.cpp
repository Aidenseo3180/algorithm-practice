#include <iostream>
#include <queue>

using namespace std;

int numStart = 0;
int M, N;
int arr[1001][1001];
int visited[1001][1001];

int saveIndex[10][2];

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(){
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];	
			int ny = y + dy[i];
			
			if (nx < N && ny < M && nx >= 0 && ny >= 0){

				if (!visited[nx][ny] && arr[nx][ny] == 0){

					visited[nx][ny] = 1;

					arr[nx][ny] = arr[x][y] + 1;
					
					q.push({nx, ny});
				}
			}
		}
	}	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 	cin >> M >> N;
 	for (int i = 0; i < N; i++){
 		for (int j = 0; j < M; j++){
 			cin >> arr[i][j];
			
			if (arr[i][j] == 1){
				q.push({i, j});
			}			
		}
	}

	bfs();

	int max = 1;
 	
 	for (int i = 0; i < N; i++){
 		for (int j = 0; j < M; j++){
 			//cout << arr[i][j] << " ";
 			if (arr[i][j] == 0){
 				cout << -1;
				 return 0;	
			}
 			
 			if (arr[i][j] > max){
 				max = arr[i][j];
			}
		}
		//cout << "\n";
	}
 	
 	cout << max - 1;
 	
 
}









