#include <iostream>

using namespace std;

int w,h;
int arr[51][51];
int visited[51][51];
int count = 0;

//possible pathways
int dx[] = {1,-1, 0, 0, 1, 1,-1, -1};
int dy[] = {0, 0, 1,-1, 1,-1, 1, -1};

void dfs(int x, int y){
	visited[x][y] = 1;
	
	for (int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (arr[nx][ny] && !visited[nx][ny]){
			dfs(nx, ny);
		}
	}
	
}

void clear(){
	count = 0;
	
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			visited[i][j] = 0;
			arr[i][j] = 0;
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(1){
    	clear();

	    cin >> w >> h;
	    
	    //0 0 : end program
	    if (!w && !h) break;
	    
	    for (int j = 0; j < h; j++){
	    	for (int i = 0; i < w; i++){
	    		//1 : land, 0 : sea
	    		cin >> arr[i][j];
			}
		}
    
    	for (int i = 0; i < w; i++){
    		for (int j = 0; j < h; j++){
    			if (arr[i][j] && !visited[i][j]){
    				count++;
    				dfs(i, j);
				}
			}
		}
    
    	cout << count << "\n";
	}
}










