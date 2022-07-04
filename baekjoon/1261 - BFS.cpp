#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define endl "\n"

using namespace std;

int N, M;
int map[100][100];
int dist[100][100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print(){
	
	cout << "---------" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------" << endl;
	
}

void BFS(){	//start : 0, 0
	queue<pair<int,int>> q;	//x, y, cnt
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		//cout << x << " " << y << endl;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			
			//if empty
			if (map[nx][ny] == 0){
				//if next > current, set next = current (bc we want minimum)
				//AND if visited before, never visit again (unless next > current). 
				if (dist[nx][ny] > dist[x][y]){
					dist[nx][ny] = dist[x][y];
					q.push(make_pair(nx, ny));
				}
			}
			
			//if wall
			else if (map[nx][ny] == 1){
				//if next > current + 1, then set next as current + 1 (bc we want minimum) 
				//AND if visited before, never visit again unless conditions meet
				if (dist[nx][ny] > dist[x][y] + 1){	
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
			
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	//input
	cin >> M >> N;
	
	for (int i = 0; i < N; i++){
		string input;
		cin >> input;
		
		for (int j = 0; j < M; j++){
			map[i][j] = input[j] - '0';	//char -> int
			
			dist[i][j] = 9999;	//Set unvisited as 9999 (high number)
		}
	}
	
	BFS();
	
	//print();
	
	cout << dist[N - 1][M - 1];
	
	return 0;	
}





