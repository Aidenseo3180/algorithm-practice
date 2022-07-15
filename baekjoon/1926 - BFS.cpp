#include <iostream>
#include <queue>
#include <algorithm>

#define endl "\n"

using namespace std;

int num_pic = 0;	//number of pictures
int max_cnt = 0;	//maximum size of picture
int temp_cnt;		//temporarily store size of picture, reset everytime
int n, m;
int map[500][500];
bool visited[500][500];

queue<pair<int,int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(int startX, int startY){
	
	temp_cnt = 1;
	q.push(make_pair(startX, startY));
	visited[startX][startY] = true;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;	
		
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];	
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
			
			if (map[nx][ny] == 1 && visited[nx][ny] == false){
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				temp_cnt++;
			}
			
		}
		
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (visited[i][j] == false && map[i][j] == 1){	
			
				BFS(i, j);
				num_pic++;
				
				if (temp_cnt > max_cnt) max_cnt = temp_cnt;
			}
		}
	}
	
	cout << num_pic << endl;
	cout << max_cnt;

	return 0;	
}
















