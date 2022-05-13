#include <iostream>
#include <queue>
#include<string.h>

using namespace std;

int arr[301][301];
int N, I;
int startX, startY;
int endX, endY;

int dx[] = {-2, -1,-2, -1, 1, 2, 1, 2};
int dy[] = {-1, -2, 1, 2, -2, -1, 2, 1};

queue<pair<int ,int >> q;

void bfs(){
	q.push({startX,startY});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			//if not out of bound & haven't visited
			if (nx >= 0 && nx < I && ny >= 0 && ny < I && !arr[nx][ny]){
				
				q.push({nx, ny});
				arr[nx][ny] = arr[x][y] + 1;
				
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 	cin >> N;
 	
 	while(N--){
 		
 		cin >> I;
 		cin >> startX >> startY >> endX >> endY;
 		
 		arr[startX][startY] = 1;
 		bfs();
 		
		cout << arr[endX][endY] -1 << "\n";
        memset(arr, 0, sizeof(arr));
	}
	
}










