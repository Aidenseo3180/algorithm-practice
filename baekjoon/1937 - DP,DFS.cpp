//https://yabmoons.tistory.com/154
#include <iostream>

using namespace std;

int map[501][501];
int DP[501][501];
int ans;
int n;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int Bigger(int A, int B){
	return A > B ? A : B;
}

int move(int x, int y){
	//DP[a][b] = c  : panda can live max c days at (a,b)
	if (DP[x][y] != 0) return DP[x][y];
	DP[x][y] = 1;
	
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];	
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		
		if (map[x][y] < map[nx][ny]){
			//recursively search & compare / store bigger value into DP
			DP[x][y] = Bigger(DP[x][y], move(nx, ny) + 1);
		}
		
	}
	return DP[x][y];
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			ans = Bigger(ans, move(i, j));
		}
	}

	cout << ans;
	
	return 0;	
}










//1st try : BFS/DFS doesn't work 
/*
#include <iostream>
#include <queue> 

#define endl "\n"

using namespace std;

int n;
int map[501][501];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int BFS(int startX, int startY){
	int x, y;
	int max_cnt = 1;
	queue<pair<pair<int,int>, int>> q;
	q.push(make_pair(make_pair(startX, startY), 1));
	
	cout << "----------" << endl;
	cout << "start : " << map[startX][startY] << endl;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		
		if (max_cnt < cnt) max_cnt = cnt;
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						
			if (map[nx][ny] > map[x][y]){
				cout << map[x][y] << " -> " << map[nx][ny] << ", cnt : " << cnt << endl;
				q.push(make_pair(make_pair(nx,ny), cnt + 1));
			}
		}
	}
	
	return max_cnt;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
   
	cin >> n;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> map[i][j];
		}
	}
   
   	int max_val = -1e9;
 	for (int i = 0; i < n; i++){
 		for (int j = 0; j < n; j++){
 			int num = BFS(i,j);
 			if (max_val < num) max_val = num;
		}
	}
   
   	cout << max_val;
   
    return 0;
}
*/









