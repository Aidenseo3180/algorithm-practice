#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define endl "\n"

using namespace std;

int R, C, N;
char map[201][201];
int time[201][201];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void installBomb(int T){
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'O') continue;
			
			map[i][j] = 'O';
			time[i][j] = T + 3;
		}
	}
}

void deleteBomb(int T){
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			
			if (time[i][j] == T){	//if same as time, explode
				
				for (int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if (map[nx][ny] == '.') continue;
					
					map[nx][ny] = '.';
					//no time[nx][ny] = 0 b/c it may affect other blocks -> so, just set map to '.'
				}	
				
				//reset current location as well
				map[i][j] = '.';
				time[i][j] = 0;
			}
		}
	}

}

void print(){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> R >> C >> N;
	
	for (int i = 0; i < R; i++){
		string input;
		cin >> input;
		
		for (int j = 0; j < C; j++){
			map[i][j] = input[j];	
			
			if (map[i][j] == 'O') time[i][j] = 3;
		}
	}
	
	int cnt_time = 2;
	while(1){
		
		if (cnt_time == N + 1) break;
		
		if (cnt_time % 2 == 0){	//when time is even, install bombs
			installBomb(cnt_time);
		}
		else{	//when odd, delete bomb
			deleteBomb(cnt_time);
		}
		
		cnt_time++;
	}
	
	print();
	
	return 0;
}











