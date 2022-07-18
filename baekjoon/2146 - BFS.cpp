#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define endl "\n"

using namespace std;

int ans = 9999;
int N;
int map[100][100];
bool visited[100][100];
int cnt[100][100];

queue<pair<int,int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void land(int startX, int startY, int num){	//label each island
	
	queue<pair<int,int>> one;
	one.push(make_pair(startX, startY));
	visited[startX][startY] = true;
	map[startX][startY] = num;
	
	while(!one.empty()){
		int x = one.front().first;
		int y = one.front().second;
		one.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			
			if (map[nx][ny] == 1 && visited[nx][ny] == false){
				map[nx][ny] = num;
				one.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int BFS(int num){
	
	for (int i = 0; i < N; i++){		//first put lands into queue, then evaluate
		for (int j = 0; j < N; j++){
			if (map[i][j] == num){
				q.push(make_pair(i, j));
			}
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
				
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];	
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						
			//if ocean & not visited before
			if (map[nx][ny] == 0 && cnt[nx][ny] == 0){
				cnt[nx][ny] = cnt[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
			
			//since BFS, as soon as we find island w/ different label, we can exit
			else if (map[nx][ny] != num && map[nx][ny] != 0){
				
				//empty the queue by swapping w/ empty version
				queue<pair<int,int>> empty;
				swap(q, empty);
				
				return cnt[x][y];
			}
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	//label each island
	int land_num = 1;	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 1 && visited[i][j] == false){
				land(i, j, land_num);
				land_num++;
			}	
		}
	}

	//then, start from surrounding of each island, increment using BFS
	for (int i = 1; i < land_num; i++){
		memset(cnt, 0, sizeof(cnt));
		int value = BFS(i);
		
		ans = min(ans, value);
	}
	
	cout << ans;

	return 0;	
}
















