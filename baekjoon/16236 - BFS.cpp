//https://fjvbn2003.tistory.com/686

#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

#define endl "\n"

using namespace std;

int N, startX, startY;
int arr[21][21];
int ans;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dist[21][21]; 

struct shark{
	int y;
	int x;	
	int size;
	int eat;
};

bool find_prey(shark& s){
	queue<pair<int,int>> q;
	memset(dist, -1, sizeof(dist));	//initialize to -1
	
	q.push({s.x, s.y});
	dist[s.x][s.y] = 0;
	
	//BFS
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		//if we found prey that we can eat ( not 9 && not 0 && size of that prey is less than our shark's size)
		if (arr[x][y] != 9 && arr[x][y] != 0 && arr[x][y] < s.size) continue;
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			//if out of scope
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			
			//if haven't visited & next location (or shark at next location) is smaller or equal to our shark, we can move through
			if (dist[nx][ny] == -1 && arr[nx][ny] <= s.size){
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	
	//find min x, y, dist
	int mx = 100;	//next starting point x
	int my = 100;	//next starting point y
	int m_dist = 401;	//min distance
	
	
	for (int i = N - 1; i >= 0; i--){
		for (int j = N - 1; j >= 0; j--){
			//if not 0 && not 9 && less than our shark's size && we've visited (has distance) && that distance is less than the current m_dist
			//then renew the m_dist, mx, my
			if (arr[i][j] != 0 && arr[i][j] != 9 && arr[i][j] < s.size && dist[i][j] != -1 && dist[i][j] <= m_dist){
				m_dist  = dist[i][j];
				mx = i;
				my = j;
			}
		}
	}
	
	//if couldn't find min distance, no more sharks exist in arr, so
	if (m_dist == 401) return false;
	else{
		arr[s.x][s.y] = 0;
		s.x = mx;
		s.y = my;
		s.eat++;
		
		if (s.eat == s.size){
			s.size++;
			s.eat = 0;
		}
		
		//next starting point
		arr[mx][my] = 9;
		ans += dist[mx][my];
		
		return true;
	}
	
}

//initial shark size : 2
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	shark s;
	
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			
			if (arr[i][j] == 9){	//if our shark location is found
				s.x = i;
				s.y = j;
				s.size = 2;
				s.eat = 0;
			}
		}
	}
	
	while(true){
		if (find_prey(s)){	//find eatable sharks
			continue;
		}
		else{		//if no more sharks exist, end while loop
			break;
		}
	}
	
	cout << ans;

	return 0;
}








