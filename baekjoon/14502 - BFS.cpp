#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[8][8];
int temp[8][8];
int c = 0;	//maximum cnt

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//copy map
void mapCopy(int (*a)[8], int (*b)[8]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			a[i][j] = b[i][j];
		}
	}
}

void bfs(){
	int spread[8][8];	//spread : virus spreading after building 3 walls
	mapCopy(spread, temp);
	queue<pair<int,int>> q;
	
	for(int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			//if virus exists, push to queue
			if (spread[i][j] == 2) 
				q.push(make_pair(i, j));
		}
	}
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;		
				
			//virus spreading overtime
			if (spread[nx][ny] == 0){
				spread[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	//count "not polluted parts"
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (spread[i][j] == 0) 
				cnt += 1;
		}
	}
	
	c = max(c, cnt);
}

void wall(int cnt){
	//when 3 walls built, spread virus
	if (cnt == 3){
		bfs();
		return;
	}
	
	//1 for loop from main + 2 for loops from here = building 3 walls without repetitive walls
	//Also, can just have 3 for loops to build wall (in a single function or main)
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (temp[i][j] == 0){
				temp[i][j] = 1;
				wall(cnt + 1);	//recursively build the wall
				temp[i][j] = 0;	//when returning from recursion, set temp back to 0
			}
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	//build walls on 0
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 0){
				mapCopy(temp, map);
				temp[i][j] = 1;	//building 1st wall
				wall(1);		//so cnt = 1
				temp[i][j] = 0;
			}
		}
	}

	cout << c;
	
	return 0;	
}





