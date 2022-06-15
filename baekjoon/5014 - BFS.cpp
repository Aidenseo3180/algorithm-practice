#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"

using namespace std;

//F : total floors
//S : current floor
//G : location of destination
//U : go up
//D : go down
long long F,S,G,U,D;
vector<bool> visited;
queue<pair<int,int>> q;

void input(){
	cin >> F >> S >> G >> U >> D;
	visited = vector<bool>(F + 1, false);
}

void BFS(){
	
	q.push({S, 0});	//current floor, cnt
	visited[S] = true;
	
	while(!q.empty()){
		int pos = q.front().first;	//current floor	
		int cnt = q.front().second;	//cnt
		q.pop();
		
		//if arrived
		if (pos == G){
			cout << cnt;
			return;	
		}
		
		//only 2 options : up or down
		if (visited[pos + U] == false && (pos + U) <= F){	//when UP
			visited[pos + U] = true;
			q.push({pos + U, cnt + 1});
		}
		
		if (visited[pos - D] == false && (pos - D) > 0){	//when DOWN
			visited[pos - D] = true;
			q.push({pos - D, cnt + 1});
		}
	}

	cout << "use the stairs";
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	input();
	BFS();

	return 0;
}








