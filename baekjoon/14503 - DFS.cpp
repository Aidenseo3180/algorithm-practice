//https://velog.io/@sj-lee33/%EB%B0%B1%EC%A4%80-14503%EB%B2%88-%EB%A1%9C%EB%B4%87-%EC%B2%AD%EC%86%8C%EA%B8%B0-c-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%ED%92%80%EC%9D%B4
#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int visited_cnt = 0;	//answer
int N, M;
int r,c,d;	//x, y of vacuum cleaner, direction
int map[51][51];
int visited[51][51];

int dx[] = {-1, 0, 1, 0};	//north, east, south, west
int dy[] = {0, 1, 0, -1};

void input(){
	cin >> N >> M;
	cin >> r >> c >> d;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	
	visited[r][c] = 1;
	visited_cnt++;
}

void dfs(){
	
	//clean 4 directions, keep turning left
	for (int i = 0; i < 4; i++){
		int next_d = (d + 3 - i) % 4;	//next direction (left)
		int next_r = r + dx[next_d];
		int next_c = c + dy[next_d];
		
		//2. if no space on left, spin to that direction & go back to (2)
		if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= M || map[next_r][next_c] == 1){
			continue;
		}
		
		//1. if uncleaned space on left exists, go there
		if (map[next_r][next_c] == 0 && visited[next_r][next_c] == 0){
			
			visited[next_r][next_c] = 1;
			r = next_r;
			c = next_c;
			d = next_d;
			visited_cnt++;
			dfs();
		}
	}
	
	int back_idx= d > 1 ? d - 2 : d + 2;	//back direction of current direction
	int back_r = r + dx[back_idx];
	int back_c = c + dy[back_idx];
	
	//C. if all 4 directions are cleaned or walls 
	//once DFS() ends, that means we're stuck somewhere (b/c above for loops recursively checks all possible directions), so only have to check the behind
	if (back_r >= 0 && back_r < N && back_c >= 0 && back_c < M){
		
		//3. if we can go back, go back & keep direction --> go back to (2)
		if (map[back_r][back_c] == 0){
			r = back_r;
			c = back_c;
			dfs();
		}
		//4. if back is blocked by wall, end
		else{
			cout << visited_cnt;
			exit(0);
		}	
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	input();
	dfs();
		
	return 0;	
}
















