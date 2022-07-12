#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

int max_cnt = 0;
int M, N, H; // N x M, H : height
int map[101][101][101];
int cnt[101][101][101];

queue<pair<int, pair<int,int>>> q;	//height, x, y

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print(){
	
	cout << "----------" << endl;
	
	for (int k = 0; k < H; k++){			//height
		for (int i = 0; i < N; i++){		//x
			for (int j = 0; j < M; j++){	//y
				cout << cnt[k][i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

void BFS(){
	
	while(!q.empty()){
		int height = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		//Upper Floor
		if (height - 1 >= 0){
			if (map[height - 1][x][y] == 0){
				map[height - 1][x][y] = 1;	//update map
				q.push(make_pair(height - 1, make_pair(x , y)));	//push next tomato
				cnt[height - 1][x][y] = cnt[height][x][y] + 1;		//count up
				if (cnt[height - 1][x][y] > max_cnt) max_cnt = cnt[height - 1][x][y];	//if current cnt + 1 > maximum cnt, 
			}
		}
		
		//Lower Floor
		if (height + 1 < H){
			if (map[height + 1][x][y] == 0){
				map[height + 1][x][y] = 1;
				q.push(make_pair(height + 1, make_pair(x , y)));
				cnt[height + 1][x][y] = cnt[height][x][y] + 1;
				if (cnt[height + 1][x][y] > max_cnt) max_cnt = cnt[height + 1][x][y];
			}	
		}
		
		//4 directions
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			
			if (map[height][nx][ny] == 0){
				
				map[height][nx][ny] = 1;
				cnt[height][nx][ny] = cnt[height][x][y] + 1;
				q.push(make_pair(height, make_pair(nx , ny)));
				
				if (cnt[height][nx][ny] > max_cnt) max_cnt = cnt[height][nx][ny];
			}
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++){			//height
		for (int i = 0; i < N; i++){		//x
			for (int j = 0; j < M; j++){	//y
				cin >> map[k][i][j];
				
				if (map[k][i][j] == 1){
					q.push(make_pair(k , make_pair(i, j)));
					cnt[k][i][j] = 0;
				}
			}
		}
	}

	BFS();

	//print();	
	
	for (int k = 0; k < H; k++){			//height
		for (int i = 0; i < N; i++){		//x
			for (int j = 0; j < M; j++){	//y
				if (map[k][i][j] == 0){
					cout << -1;
					return 0;
				}
			}
		}
	}
	
	cout << max_cnt;

	return 0;	
}




