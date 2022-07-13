#include <iostream>
#include <queue>
#include <set>

#define endl "\n"

using namespace std;

string map = "";	//current state of map, save as string to save spaces
int ans = -1;		//ans

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void BFS(){
	queue<pair<string,int>> q;	//current state of map, counts
	q.push({map, 0});
	
	set<string> check;		//avoid overlapping state of map (shortest path)
	
	while(!q.empty()){
		string state = q.front().first;
		int cnt = q.front().second;
		q.pop();	
		
		//if reached goal
		if (state == "123456780" && (ans == -1 || ans > cnt)){
			ans = cnt;
		}
		
		int curr = state.find('0');	//location of 0 (its string index using 0th indexing)
		
		int col = curr / 3;	//finding current col of 0
		int row = curr % 3;	//finding current row of 0
		
		//try all 4 directions
		for (int i = 0; i < 4; i++){
			int ny = col + dx[i];
			int nx = row + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
			
			//***don't need to check for visited b/c if overlap exists, set will get rid of it
			
			string curState = state;	//change the state
			
			//swap current w/ next
			swap(curState[col * 3 + row], curState[ny * 3 + nx]);
			
			//if curState doesn't exist in set,
			//at the end, if only overlaps exist, then queue becomes empty, leaves while loop
			if (check.count(curState) == false){
				check.insert(curState);
				q.push({curState, cnt + 1});	
			}
		}		
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			char c;
			cin >> c;
			
			map += c;
		}
	}

	BFS();
	
	cout << ans;

	return 0;	
}


/*
explanation :

in 3x3 matrix, if map is :
1 2 3
4 5 0
6 7 8

map = "123450678" in string,

map.find('0') --> return index using 0th indexing, so --> 5

col = 5 / 3 = 1,
row = 5 % 3 = 2,

then we swap 0 w/ next element (found w/ nx, ny)

if ny = 1(col) + 1 = 2, nx = 2 (row) + 0 = 2,

map at 2,2 = 8, map at col, row = 0

in string, index is a little different, so we have to calculate :

col * 3 + row = 1 * 3 + 2 = 5 (which is the same as index of 0 that found earlier)
ny * 3 + nx = 2 * 3 + 2 = 8 (and from string "12345078", 8th is '8')

therefore, 0 & 8 gets flipped

this takes place as for loop searches all 4 directions & proceed until q gets emptied out

*/




