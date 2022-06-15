#include <iostream>
#include <queue>
#include <string.h>

#define endl "\n"

using namespace std;

int N, M;
int cheese[101][101];
bool visited[101][101] = {0,};
int counts[101][101] = {0,};

queue<pair<int,int>> q;

int dx[] = { 1, 0, -1, 0};
int dy[] = {0, 1, 0 , -1};

void BFS(int startX, int startY){
	
	q.push({startX, startY});
	visited[startX][startY] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			
			if (visited[nx][ny] == false){
				//if cheese is in contact with air & count is less than 2 (prevent visiting melted cheese spot)
				if (cheese[nx][ny] == 0 && counts[nx][ny] < 2){
					q.push({nx,ny});
					visited[nx][ny] = 1;
				}
				//if next cheese is found, check count, and melt it
				if (cheese[nx][ny] == 1 && counts[nx][ny] < 2){
					counts[nx][ny] += 1;
					if (counts[nx][ny] == 2){
						cheese[nx][ny] = 0;
					}
				}
			}
		}
	}
}

//check cheese
void check(){
	cout << "----------------" << endl;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << cheese[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> cheese[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (cheese[i][j] == 1){	//if cheese exists
				BFS(0, 0);	//start from 0, 0 (air)
				cnt++;
				
				//check();
				
				memset(counts, 0, sizeof(counts));
				memset(visited, false, sizeof(visited));
			}
		}
	}
		
	cout << cnt;

	return 0;
}








