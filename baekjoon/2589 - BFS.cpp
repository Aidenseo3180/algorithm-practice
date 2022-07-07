#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

#define endl "\n"

using namespace std;

int max_val = -1e9;
int N, M;
char map[50][50];
int cnt[50][50] = {0,};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print(){
	
	cout << "------------" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(int startX, int startY){
	queue<pair<int,int>> q;
	q.push(make_pair(startX,startY));
	cnt[startX][startY] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (cnt[x][y] > max_val) max_val = cnt[x][y];
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
						
			if (map[nx][ny] == 'L' && cnt[nx][ny] == -1){
				
				q.push(make_pair(nx,ny));
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++){
		string input;
		cin >> input;
		
		for (int j = 0; j < M; j++){
			map[i][j] = input[j];
			
			cnt[i][j] = -1;	//cnt works as both counter & visited status
		}
	}

	BFS(4,1);

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//try all the possible combinations w/ BFS
			if (map[i][j] == 'L'){
				BFS(i, j);

				memset(cnt, -1, sizeof(cnt));
			}
		}
	}

	cout << max_val;

	return 0;	
}



















