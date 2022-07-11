#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

int N, K;
int S, X, Y;
int cnt = 0;

int map[201][201];
queue<pair<pair<int,int>, int>> q;
vector<pair<int, pair<int,int>>> v;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void print(){
	cout << "-------------" << endl;	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(){
	
	int c = 0;
	while(c != cnt){	//compare w/ cnt, if c == cnt, 1 sec passed!
		int x = q.front().first.first;
		int y = q.front().first.second;
		int num = q.front().second;
		
		c++;	//count how many times elements have been called from queue
		
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;
			
			if (map[nx][ny] == 0){
				
				map[nx][ny] = num;
				q.push(make_pair(make_pair(nx, ny), num));
			}
		}
	}
	cnt = q.size();	//set cnt as size of queue (for next second)
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
			
			if (map[i][j] != 0){
				v.push_back(make_pair(map[i][j], make_pair(i, j)));
			}
		}
	}
	
	//sort by number
	sort(v.begin(), v.end());
	
	//assign to queue
	for (int i = 0; i < v.size(); i++){
		
		int x1 = v[i].second.first;
		int y1 = v[i].second.second;
		int n = v[i].first;
		
		cnt++;
		q.push(make_pair(make_pair(x1, y1), n));	
	}
	
	cin >> S >> X >> Y;
	
	//run S times (S seconds)
	for (int i = 1; i <= S; i++){
		
		BFS();
		
		//print();
		
		//if answer is already filled, break (no point of continuing)
		if (map[X][Y] != 0) break;
	}
	
	//answer :
	cout << map[X][Y];

	return 0;	
}



















