#include <iostream>
#include <string>
#include <queue>

#define MAX 102
using namespace std;

int N, M;
char arr[MAX][MAX] = {'0'};
int visited[MAX][MAX] = {0};
int check[MAX][MAX] = {0};
queue<pair<int, int>> q;

//x
int dx[] = {1,-1,0,0};
//y
int dy[] = {0,0,1,-1};
int x, y;

//BFS (used to find shortest path)
void maze(){
	//starting point	
	pair<int,int> p = {1,1};
	q.push(p);
	visited[1][1] = 1;
	check[1][1] = 1;
	
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++){
			//new coordinate
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//check
			//new coordinates can't be negative or exceed limit, check if it's 1 
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M){
				if (arr[nx][ny] == '1' && visited[nx][ny] == 0){
					q.push({nx, ny});
					visited[nx][ny] = 1;
					check[nx][ny] = check[x][y] + 1;	//add each time to keep a number (so that we can find the shortest path)
				}
			}	
		}
	}

}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++){
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++){
			arr[i][j] = str[j-1];			
		}
	}
	
	maze();
	
//	for (int i = 1; i <= N; i++){
//		for (int j = 1; j <= M; j++){
//			
//			cout << check[i][j] << " ";	
//		}
//		cout << "\n";
//	}
	
	
	cout << check[N][M];
		
}










