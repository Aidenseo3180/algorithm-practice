#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int n;
int map[51][51];
int visited[51][51];

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void BFS(){
	
	//set all the visit as high number, and compare each one of them w/ our current counts
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			visited[i][j] = 999;
		}
	}
	
	queue<pair<int,int>> q;	//y, x, wall number
	q.push(make_pair(0,0));	
	visited[0][0] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			
			//if not wall
			if (map[ny][nx] == 1){
				//if current visit is lower than next visit, then update next visit as current visit value
				if (visited[y][x] < visited[ny][nx]){
					visited[ny][nx] = visited[y][x];
					q.push(make_pair(ny,nx));	
				}
			}
			//if wall
			else{
				//if current visit + 1 is lower thhan next visit
				//+ 1 : count up as we go through wall
				if ( visited[y][x] + 1 < visited[ny][nx]){
					visited[ny][nx] = visited[y][x] + 1;
					q.push(make_pair(ny,nx));
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++){
		string input;
		cin >> input;
		
		for (int j = 0; j < n; j++){
			//0 : black room (wall), 1 : white room
			map[i][j] = input[j] - '0';
		}
	}
	
	//0,0 always start
	//goal : n-1 x n-1
	BFS();

	cout << visited[n-1][n-1] << endl;

	return 0;
}












