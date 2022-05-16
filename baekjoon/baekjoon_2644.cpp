//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, p1, p2;

int arr[101];
int visited[101];
queue<int> q;
vector<int> v[101];

//bfs using array-lists
void bfs(int point){
	q.push(point);
	visited[point] = 1;
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		//move through the connected nodes
		for (int i = 0; i < v[x].size(); i++){
			//new location
			int y = v[x][i];
			
			if (!visited[y]){
				q.push(y);
				visited[y] = 1;
				
				//add up as it moves through
				arr[y] = arr[x] + 1;
			}
		}	
	}
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	cin >> p1 >> p2;
	cin >> M;
	
	int input1, input2;
	for (int i = 0; i < M; i++){
		cin >> input1 >> input2;
		v[input1].push_back(input2);
		v[input2].push_back(input1);
	}
	
	bfs(p1);
	
	if (arr[p2] == 0) cout << -1;
	else cout << arr[p2];

	return 0;
}



