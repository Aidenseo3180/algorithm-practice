//https://yabmoons.tistory.com/117
//https://conkjh032.tistory.com/401
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char arr[5][5];
int selected[26];
int ans = 0;

int g[5][5];
int visited[5][5];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//check if they're connected (by BFS)
bool check(){
	
	memset(visited, 0, sizeof(visited));
	memset(g, 0, sizeof(g));
	
	//mark selected students as 1 & store in array g 
	int x, y;
	for (int i = 0; i < 25; i++){
		if (selected[i] == 0) continue;
		
		y = i / 5;
		x = i % 5;
		
		g[y][x] = 1;	//selected에 있던 학생들만 따로 1을 넣어줌 (이게 더 편하니까. 매번 selected[i / 5][i % 5] 할 필요 없이 여기서 다 그냥 끝내는것) 
	}
	
	queue<pair<int,int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	
	int cnt = 1;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;			
			if (visited[ny][nx] == true) continue;
			
			if (g[ny][nx] == 1){
				cnt++;
				q.push({ny, nx});
				visited[ny][nx] = 1;
			}
		}
	}
	
	if (cnt == 7) return true;
	return false;
}

//Combination
void DFS(int idx, int total, int cnt_s){	//idx = depth, total = cnt, cnt_s = number of 'S'
	
	if (total == 7){
		if (cnt_s >= 4){
			if (check() == true) ans++;
		}
		return;
	}
	
	for (int i = idx; i < 25; i++){
		if (selected[i] == true) continue;	
		
		selected[i] = true;
		DFS(i, total + 1, cnt_s + (arr[i / 5][i % 5] == 'S'));	//x = i / 5, y = i % 5  <-  if true, adds 1 to cnt_s (true = 1)
		selected[i] = false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	
	DFS(0, 0, 0);
	
	cout << ans;

	return 0;
}








