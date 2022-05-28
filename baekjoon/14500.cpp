#include <iostream>
#include <cstring>

#define endl "\n"

using namespace std;

int N, M, ans = 0;
int map[501][501];
bool visited[501][501];	//bool works, but int doesn't (why...?)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

//compare sum and ans to find biggest number
int bigger(int a, int b){
	if (a > b) return a;
	return b;
}

void Input(){
	cin >> N >> M;	//y, x

	for (int i = 0; i < N; i++){	//rows
		for (int j = 0; j < M; j++){	//columns
			cin >> map[i][j];
		}
	}
}

//for shapes with depth = 3 (0, 1, 2, 3. so 4 in size)
void DFS(int y, int x, int sum, int cnt){
	visited[y][x] = true;
	
	if (cnt == 3){
		ans = bigger(sum, ans);
		return;
	}
	
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (nx < 0 || ny < 0 || ny >= N || nx >= M) continue;
		
		if (visited[ny][nx]) continue;
		
		DFS(ny, nx, sum + map[ny][nx], cnt + 1);
		visited[ny][nx] = false;	//backtracking so tha we can search for flip version
	}
}

//for purple tetranominos
void s1(int y, int x){	//で 
    int tsum=0;
    tsum = map[y][x] + map[y][x+1] + map[y][x+2] + map[y-1][x+1];
    if(tsum>ans)
        ans=tsum;
}

void s2(int y, int x){	// ぬ 
    int tsum=0;
    tsum = map[y][x] + map[y][x+1] + map[y][x+2] + map[y+1][x+1];
    if(tsum>ans)
        ans=tsum;
}

void s3(int y, int x){	//た  
    int tsum=0;
    tsum = map[y][x] + map[y+1][x] + map[y+2][x] + map[y+1][x+1];
    if(tsum>ans)
        ans=tsum;
} 

void s4(int y, int x){	//っ 
    int tsum=0;
    tsum = map[y][x] + map[y-1][x+1] + map[y][x+1] + map[y+1][x+1];
    if(tsum>ans)
        ans=tsum;
}

void Solution(){
	//check each blocks
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			memset(visited, 0, sizeof(visited));
			
			//at each block, check all the tetranomino (all blocks of depth = 3 + all the special cases)
			
			DFS(i, j, map[i][j], 0);	//for tetranominos other than purple (depth = 3)
			
			//for purple tetranomino (で, ぬ, た, っ) 
			
			if(i - 1 >= 0 && j + 2 < M ) s1(i,j);	//preconditions, if it doesn't exceed N x M size, 
            if(i + 1 < N && j + 2 < M ) s2(i,j);
            if(i + 2 < N && j + 1 < M ) s3(i,j);
            if(i + 1 < N && i - 1 >= 0 && j + 1 < M ) s4(i,j);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	Input();
	Solution();

	cout << ans;

	return 0;
}


