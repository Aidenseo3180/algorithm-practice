#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int max_value = 0;
int counter = 0;

int visited[102][102] = {0};
int arr[102][102];

//by doing this, we can access different locations of matrix (important!)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int loop_count){
	//check left, right, up, down everytime
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];	
		int ny = y + dy[i];
		
		//if that new location is : greater than drowning value && haven't visited yet
		if (arr[nx][ny] > loop_count && visited[nx][ny] == 0){
			visited[nx][ny] = 1;
			dfs(nx, ny, loop_count);	//then check that location recursively
		}
	}
}

//reset visited array
void reset(){
	
	counter = 0;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			visited[i][j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N;
	//input
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			
			if (arr[i][j] > max_value){
				max_value = arr[i][j];
			}	
		}
	}
	//loop through from 0 ~ max number to find highest
	vector<int> result;
	int loop_count = 0;

	while(loop_count <= max_value){
		
		reset();
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				//이건 한번 돌아가면 group을 뭉텅이로 다 visited으로 만들어서 counter++하면 한 그룹씩 카운트 가능!
				//visited를 하는건 dfs에서 됨 
				if (arr[i][j] > loop_count && visited[i][j] == 0){
					//count groups up as this part runs
					counter++;
					visited[i][j] = 1;
					dfs(i, j, loop_count);
				}
				
			}
			
		}
		result.push_back(counter);
		loop_count++;
	}

	cout << *max_element(result.begin(), result.end());

	
}










