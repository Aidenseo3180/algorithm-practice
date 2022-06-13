#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<tuple>
#include<cstring>
#pragma warning(disable:4996)

using namespace std;

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char map[51][51];
int water[51][51];
int d[51][51];
int startx;
int starty;
int destinationx;
int destinationy;
int waterx;
int watery;
queue<pair<int, int>> q;

void water_bfs() {
    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (map[nx][ny] == '.' && water[nx][ny] == -1 ) {
                water[nx][ny] = water[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void bfs() {
    int x, y;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (d[nx][ny] != -1) continue;
            if (map[nx][ny] == 'X') continue;
            if (d[x][y] + 1 >= water[nx][ny] && water[nx][ny] != -1) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    memset(water, -1, sizeof(water));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '*') {
                q.push(make_pair(i, j));
                water[i][j] = 0;
            }
            if (map[i][j] == 'S') {
                startx = i;
                starty = j;
                d[i][j] = 0;
            }
            if (map[i][j] == 'D') {
                destinationx = i;
                destinationy = j;
            }
        }
    }
    water_bfs();
    q.push(make_pair(startx, starty));
    bfs();
    if (d[destinationx][destinationy] == -1) {
        cout << "KAKTUS" << "\n";
    }
    else {
        cout << d[destinationx][destinationy] << "\n";
    }

}

/*
#include <iostream>
#include <queue>
#include <string>
#include <string.h>

#define endl "\n"

using namespace std;

char map[51][51];
queue<pair<int,int>> hedge;	//movvement of hedgehog
queue<pair<int,int>> water;	//movement of water

int next_hedge[51][51];
int next_water[51][51];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	//input :
	int R, C;
	cin >> R >> C;
	
	memset(next_hedge, -1, sizeof(next_hedge));
	memset(next_water, -1, sizeof(next_water));
	
	for (int i = 0; i < R; i++){		
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
						
			if (map[i][j] == '*'){
				water.push({i, j});
				next_water[i][j] = 0;
			}
			
			if (map[i][j] == 'S'){
				hedge.push({i, j});
				next_hedge[i][j] = 0;
			}
		}
	}

	//water bfs :
	while(!water.empty()){
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
				
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//if out of bound, skip
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			
			if (next_water[nx][ny] != -1) continue;
			if (map[nx][ny] == 'X') continue;
			if (map[nx][ny] == 'D') continue;
			
			water.push({nx, ny});
			next_water[nx][ny] = next_water[x][y] + 1;
		}
	}

	//hedge bfs :
	while(!hedge.empty()){
		int x = hedge.front().first;
		int y = hedge.front().second;
		hedge.pop();
			
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//if arrives on time
			if (map[nx][ny] == 'D'){
				cout << next_hedge[x][y] + 1;
				
				return 0;
			}
			
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (next_hedge[nx][ny] != -1) continue;
			if (map[nx][ny] == 'X') continue;
			if (next_water[nx][ny] <= next_hedge[x][y] + 1) continue;
			//same as next_water[nx][ny] > next_hedge[x][y] + 1
				
			next_hedge[nx][ny] = next_hedge[x][y] + 1;
			hedge.push({nx, ny});
		}
	}
	
	//if can't get to 'D'
	cout << "KAKTUS";
	
	return 0;
}
*/















