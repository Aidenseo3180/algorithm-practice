#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int map[1001][1001] = {0,};
int visited[1001][1001][2];	//x, y, whether the wall can be went through
//works as both visited and cnt (if 0, haven't visited, but > 0, visited & cnt up)

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int BFS(){
	
	queue<pair<pair<int,int>, int>> q;
	q.push({{1, 1}, 1});	//x, y, number of times you can go through wall
	visited[1][1][1] = 1;
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;	//whehter I've already went through the wall
		q.pop();

		//if reaches the goal
		if (x == N && y == M){
			return visited[x][y][block];	//since we have to coutn the last one too, it's [block], not [block-1]
		}
		
		//basically, you go through all the walls near 0 (road), but don't go further once you've gone through that wall
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > M) continue;
			
			//if wall && if you haven't gone through wall , then go through that wall
			if (map[nx][ny] == 1 && block){
				visited[nx][ny][block - 1] = visited[x][y][block] + 1;	//add up
				q.push({{nx,ny}, block - 1});	//set block - 1 so that  
			}	
			//if map is 0 (not a wall) & if you haven't visited
			else if (map[nx][ny] == 0 && visited[nx][ny][block] == 0){
				visited[nx][ny][block] = visited[x][y][block] + 1;	//add up
				q.push({{nx, ny}, block});
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++){
		string temp;
		cin >> temp;
		
		for (int j = 0; j < M; j++){
			map[i][j + 1] = temp[j] - '0';
		}
	}

	cout << BFS();
	
	return 0;
}

//explanation : 
/*
Only can go through the wall once, but since we're looking for the shortest path w/ BFS, we can go through all the wall that are near the road (all the 1s around 0).
And after you go through that wall, set block to be block - 1 at that point (so, push {{x, y},block -1} 
When you move to the next location (where wall has been destroyed), since block at that point is 0, you can't go through the wall anymore 
(prevent going through another wall at that location)

ex) 0 1 1 -> 0 0 1 (went through wall, this is fine - wall near 0)
		  -> 0 0 0 (BUT this is NOT OK. since you've already went through wall, when you're standing on top of where the wall was at, you can't go through another wall
		  			and we indicate this by block (if block == 1, can go though wall, if not, block == 0)

so, 0 1 1	-> 0 0 1						->	0 0 0 (NOT allowed)
	1 1 1	   0 1 1 (fine)						0 0 1
		above going through all the walls near 0.


above ex. in terms of block :
	1 1 1  -> 1 0 1	(since block is 0 at these places where walls were located,		-> so, can go through another walls where block == 0
    1 1 1	  0 1 1	 can't go through anymore)
    
*/


