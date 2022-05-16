#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, input1, input2;
int count = 0;
int visited[501];
int arr[501];

vector<int> v[501];
queue<int> q;

void bfs(int start){
	visited[start] = 1;
	q.push(start);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
	
		for (int i = 0; i < v[x].size(); i++){
			
			int y = v[x][i];
			
			//if hasn't been visited AND arr[x]+1 is less than 3 (because friend of friend is fine, but not beyond that)
			if (!visited[y] && arr[x]+1 < 3){
				visited[y] = 1;
				q.push(y);
				arr[y] = arr[x] + 1;
				count++;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++){
		cin >> input1 >> input2;
				
		v[input1].push_back(input2);
		v[input2].push_back(input1);
	}

	bfs(1);

	cout << count;

	return 0;	
}



