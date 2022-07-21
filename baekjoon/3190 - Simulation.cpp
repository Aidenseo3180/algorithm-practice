#include <iostream>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int map[101][101];	//if 1, apple exists
bool is_there_snake[101][101];
int N, K, L;	//board size, num of apples, num of change in direction

int dy[] = {0, 1, 0, -1};	//right, bottom, left, top
int dx[] = {1, 0, -1, 0};

//at certain time, switch direction
char swift[10001];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
		
	for (int i = 0; i < K; i++){
		int x, y;
		cin >> x >> y;
		
		map[x][y] = 1;	//location of apple
	}
	
	cin >> L;
	
	for (int i = 0; i < L; i++){
		int time;
		char direc;
		cin >> time >> direc;
		
		swift[time] = direc;
	}
	
	queue<pair<int,int>> snake;
	
	//snake start
	snake.push({1, 1});
	//where snake is located
	is_there_snake[1][1] = true;
	
	//time (answer)
	int ans_time = 0;
	//current direction, start w/ right (first element of dy, dx arrays)
	int curr_direc = 0;
	
	while(1){
	
		ans_time++;
		
		int next_col = snake.back().first + dy[curr_direc];
		int next_row = snake.back().second + dx[curr_direc];
	
		//if hit the wall, exit
		if (next_row < 1 || next_col < 1 || next_row > N || next_col > N) break;
		
		snake.push({next_col, next_row});	//snake back() : head of snake, snake front() : tail of snake
		
		//switch direction
		if (swift[ans_time] == 'D'){
			curr_direc += 1;
			if (curr_direc == 4) curr_direc = 0;	
		}
		else if (swift[ans_time] == 'L'){
			curr_direc -= 1;
			if (curr_direc == -1) curr_direc = 3;
		}
		
		//if apple exists, don't move tail
		if (map[next_col][next_row] == 1){
			map[next_col][next_row] = 0;
		}
		//if apple is not there, move tail
		else{
			if (is_there_snake[next_col][next_row] == true) break;
			
			is_there_snake[snake.front().first][snake.front().second] = false;
			snake.pop();
		}
		
		//if snake body exists, break
		if (is_there_snake[next_col][next_row] == true) break;
		
		//if not, move snake to next location
		else is_there_snake[next_col][next_row] = true;
		
	}
	cout << ans_time;
	
	return 0;	
}
















