#include <iostream>

using namespace std;

int T; //number of test cases

int M, N, K; //M : horizontal, N : vertical, K : number of cabbages 
int sum;

int arr[52][52];
int visited[52][52];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
	
	//search around
	for (int a = 0; a < 4; a++){
		int nx = x + dx[a];
		int ny = y + dy[a];
		
		//if conditions meet
		if (nx >= 0 && nx < M && ny >= 0 && ny < N){
			if (arr[nx][ny] == 1 && visited[nx][ny] == 0){
				visited[nx][ny] = 1;
				dfs(nx, ny);
			}
		}
	}
}

//reset
void clean(){
	sum = 0;
	
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while(T--){
    	//reset
		clean();
		
    	cin >> M >> N >> K;
    	int x, y;
    	
    	for (int i = 0; i < K; i++){
    		cin >> x >> y;
    		arr[x][y] = 1;
		}
		
		//find
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (arr[i][j] == 1 && visited[i][j] == 0){
					sum++;
					visited[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		cout << sum << "\n";
	}  
}










