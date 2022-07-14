#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

int temp_cnt = 0;
char map[12][6];
int visited[12][6];

vector<pair<int,int>> boom_temp;	//temporary store those that are the same
vector<pair<int,int>> boom_explode;	//later, if 4+ exists, put them here & get rid of them

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int x, int y){
	
	for (int i = 0; i < 4; i++){
		
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
		if (map[nx][ny] == '.') continue;
		if (map[nx][ny] != map[x][y]) continue;
		if (visited[nx][ny] == true) continue;
		
		temp_cnt++;
		visited[nx][ny] = true;
		boom_temp.push_back(make_pair(nx, ny));
		DFS(nx, ny);
		
	}
}

void solution(){
	
	bool flag;	//if 4+ exists, signal to explode them
	int ans = 0;

	while(1){
		flag = false;
		memset(visited, 0, sizeof(visited));
		boom_explode.clear();	//clean vector of exploding elements
		
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 6; j++){
				if (map[i][j] != '.' && visited[i][j] == false){
					
					temp_cnt = 1;	
					boom_temp.push_back(make_pair(i, j));
					visited[i][j] = 1;
					
					DFS(i, j);
					
					if (temp_cnt >= 4){
						
						flag = true;	//mark them as exploded
						
						for (int i = 0; i < boom_temp.size(); i++){
							boom_explode.push_back(boom_temp[i]);
						}
						
					}
					boom_temp.clear();	//reset temp vector for 4+ of same elements
				}
			}
		}
		
		//change those that are exploding as '.'
		for (int i = 0; i < boom_explode.size(); i++){
			int x = boom_explode[i].first;
			int y = boom_explode[i].second;
			
			map[x][y] = '.';
		}
		
		for (int i = 10; i >= 0; i--){	//0 ~ 10, 11th is the bottom part of puyopuyo (12 in total, since 0th indexing, goes from 0 to 11)
			for (int j = 0; j < 6; j++){
				if (map[i][j] == '.') continue;
				
				int tmp = i;
				
				while(1){
					//tmp = 11 <- the bottom-most element. Since no where to go down, no point of continuing -> break
					if (map[tmp + 1][j] != '.' || tmp == 11) break;	//if 1 element under current is '.', no point of continuing
					
					map[tmp + 1][j] = map[tmp][j];	//marbles moving to bottom
					map[tmp][j] = '.';
					tmp++;
					
				}
			}
		}

		//if explosion happened, increment count
		if (flag == true){
			ans++;
		}
		else break;	//if explosion didn't happen, that means there are no matches exist, so end	
	}
	
	cout << ans;
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			cin >> map[i][j];
		}
	}

	solution();

	return 0;	
}
















