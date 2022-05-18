#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int input_y, input_x;
int cheese[101][101];
int visited[101][101];
int cnt, ans = 0;
int time = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int,int>> q;

bool bfs(){
	q.push({0,0});
	visited[0][0] = 1;
	time++;
	cnt = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx < 0 || ny < 0 || ny >= input_y || nx >= input_x) continue;
			
			if (!visited[ny][nx]){
				
				if (cheese[ny][nx] == 0){
					q.push({ny, nx});
				}	
				
				//if 1
				else if (cheese[ny][nx] == 1){
					cheese[ny][nx] = 0;
					cnt++;	//count number of cheeses in contact with the air
				}
				visited[ny][nx] = 1;
			}
		}
	}
	
	//when the queue is empty
	
	//if cnt is 0 (meaning there's no cheese left)
	if (cnt == 0){
		cout << --time << "\n" << ans;
		return true;
	}
	//if cheese exists
	else{
		ans = cnt;	//save the number of cheeses in contact with air into result
		return false;
	}
	
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> input_y >> input_x;
	
	for (int i = 0; i < input_y; i++){
		for (int j = 0; j < input_x; j++){
			cin >> cheese[i][j];
		}
	}
	
	while(true){
		if (bfs()){
			break;
		}
		//reset visit status
		memset(visited, false, sizeof(visited));
	}
	
}



















