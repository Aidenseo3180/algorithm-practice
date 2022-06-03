#include <iostream>
#include <cstring>
using namespace std;
 
int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
int changeDir_1[] = { 1,0,3,2 };
int changeDir_2[] = { 3,2,1,0 };
 
int N, M;
char map[502][502];
bool visited[502][502][4];	//y, x, direction
int si, sj;
 
 //for output :
char direction[] = { 'U','R','D','L' };
int cnt = 0;	//count
int dirIndex;	//saved index (from first for loop)
bool isVoyager = false;	//check if voyager
 
int main() {
 
    //ют╥б
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    //space probe
    cin >> si >> sj;
 
    //search 4 directions from starting point
    for (int i = 0; i < 4; i++) {
 
        //reset
        memset(visited, false, sizeof(visited));
        int nx = si;
        int ny = sj;
        int dir = i;
        int time = 1;
        visited[si][sj][i] = true;
 
 		//keep runnxng until break
        while (true) {
 
 			//movement of x and y over time
            nx += di[dir];
            ny += dj[dir];
 
            //if next location meets C OR out of bound = break
            if (nx <= 0 || ny <= 0 || nx > N || ny > M || map[nx][ny] == 'C') {
                break;
            }
 
            //if we've visited next location with same direction
            if (visited[nx][ny][dir]) {
                isVoyager = true;
                break;
            }
 
            if (map[nx][ny] == '.') {	//if ., pass (don't do anything)
                
            }
            else if (map[nx][ny] == '/') {
                dir = changeDir_1[dir];
            }
            else {
                dir = changeDir_2[dir];
            }
            visited[nx][ny][dir] = true;
            time++;
        }
 
        //save result
        if (isVoyager) {
            dirIndex = i;
            break;
        }
        
        //if current cnt is > previous cnt, update
        else {
            if (time > cnt) {
                cnt = time;
                dirIndex = i;
            }
        }
    }
 
    //output
    if (isVoyager) {
        cout << direction[dirIndex] << "\n" << "Voyager";
    }
    else {
        cout << direction[dirIndex] << "\n" << cnt;
    }
}


//My Attempt, works but website doesn't take as an answer
/*

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define endl "\n"

using namespace std;

int sd = 0;	//saves the direction
int N, M, PR, PC;
char arr[500][500];
int cnt[500][500] = {0,};
vector<pair<int, int>> v;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int direction[] = {1,2,3,4};	// 1 : U, 2 : R, 3 : D, 4 : L

bool cmp(const pair<int,int> &a, const pair<int,int> &b){	//compare
	
	if (a.first == b.first){	//if the same
		for (int i = 0; i < 4; i++){
			if (a.second == direction[i]){	//sort by U, R, D, L order
				return false;
			}
			if (b.second == direction[i]){
				return false;
			}
		}
	}
	return (a.first > b.first);
}

void dfs(int y, int x, int d){

	//if it runs more than 200, it's most likely a "voyager"
	if (cnt[y][x] > 200){
		
		v.push_back({999, sd});
		return;
	}
	
	//when it meets the planet, changes direction
	if (arr[y][x] == '.'){
		
	}
	else if (arr[y][x] == '/'){
		if (d == 1) d = 2;		//up -> right
		else if (d == 2) d = 1;	//left -> up
		else if (d == 3) d = 4;	//down -> left
		else if (d == 4) d = 3;	//left -> down
	}
	// \ case
	else{
		if (d == 1) d = 4;		//up -> left
		else if (d == 2) d = 3;	//right -> down
		else if (d == 3) d = 2;	//down -> right
		else if (d == 4) d = 1;	//left -> up
	}
	
	int nx, ny;
	ny = y + dy[d - 1];
	nx = x + dx[d - 1];
	
	//if next point is out of bound, end & calculate for max
	if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 'C'){

		v.push_back({cnt[y][x], sd});
		return;
	}
	
	//count up
	cnt[ny][nx] = cnt[y][x] + 1;
	dfs(ny, nx, d);
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	//location of space probe
	cin >> PR >> PC;
	
	for (int i = 0; i < 4; i++){
		
		cnt[PR - 1][PC - 1] = 1; 	//using 0th indexing

		sd = direction[i];			//save direction for output
		dfs(PR - 1, PC - 1, direction[i]);
		
		memset(cnt, 0, sizeof(cnt));	//reset for next direction
	}	
	
	
	sort(v.begin(), v.end(), cmp);
	
//	for (auto a : v){
//		cout << "total : " << a.first << ", direction : " << a.second << endl;
//	}
	
	//output :
	char ddd[] = {'U', 'R', 'D', 'L'};
	cout << ddd[v[0].second - 1] << endl;
	
	if (v[0].first == 999){
		cout << "Voyager";
	}
	else cout << v[0].first;
	
	
	return 0;
}


*/
