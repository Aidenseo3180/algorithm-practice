#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int input;
int sum = 0;
int arr[27][27];
int visited[27][27];

//int order[27][27];
//int order_count = 0;

vector<int> v;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y){
	
	//order_count++;
	//order[x][y] = order_count;
	
	//check top, bottom, left, right
	for (int a = 0; a < 4; a++){
		int nx = x + dx[a];
		int ny = y + dy[a];
	
		if (arr[nx][ny] == 1 && visited[nx][ny] == 0){
			sum++;
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin >> N;
	
	string input;
	for (int i = 0; i < N; i++){
		cin >> input;
		
		for (int j = 0 ; j < N; j++){
			arr[i][j] = input[j] - '0';
		}
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			
			//if these conditions are met, start searching through
			if (arr[i][j] == 1 && visited[i][j] == 0){
				sum++;
				visited[i][j] = 1;
				dfs(i, j);
			}
			
			if (sum > 0){
				v.push_back(sum);
			}
			sum = 0;

		}
	}
	
	//to check the ordering:
	
//	for (int i = 0; i < N; i++){
//		for (int j = 0; j < N; j++){
//			cout << order[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	
	sort(v.begin(), v.end());
	cout << v.size();
	for (auto x : v){
		cout << "\n";
		cout << x;
	}
	
}










