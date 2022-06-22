#include <iostream>

#define endl "\n"

using namespace std;

int R, C;
string map[11];
bool visited[11][11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> R >> C;
	
	for (int i = 0; i < R; i++){
		cin >> map[i];
	}
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'X'){
				visited[i][j] = true;
				int cnt = 0;
				
				for (int a = 0; a < 4; a++){	//search 4 directions
					
					int x = i + dx[a];
					int y = j + dy[a];
					
					if (visited[x][y] == true) continue;	//prevent to visit place where it used to be 'X' but now '.'
					
					if (x < 0 || y < 0 || x >= R || y >= C) cnt++; 	//if out of bound, count up
					else if (map[x][y] == '.') cnt++;	//if ocean, count up
					
					//if condition met, island drowns
					if (cnt >= 3){
						map[i][j] = '.';
					}
				}
			}
		}
	}
	
	//find min,max x and y to print
	int min_x = 999;
	int max_x = 0;
	int min_y = 999;
	int max_y = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'X'){
				
				if (i < min_x) min_x = i;
				if (i > max_x) max_x = i;
				if (j < min_y) min_y = j;
				if (j > max_y) max_y = j;
				
			}
		}
	}

	for (int i = min_x; i <= max_x; i++){
		for (int j = min_y; j <= max_y; j++){
			cout << map[i][j];
		}
		cout << endl;
	}

    return 0;
}












