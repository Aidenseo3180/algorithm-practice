#include <iostream>
#include <queue>

using namespace std;

int N;
int arr[1001];		//values
int visited[1001];	//visit status

queue<pair<int, int>> q;

void bfs(){
	
	q.push({0,0});
	visited[0] = 1;
	
	while(!q.empty()){
		
		int index = q.front().first;	//index
		int cnt = q.front().second;		//counter
		q.pop();

		//if reaches the end
		if (index == N - 1){
			cout << cnt;
			return;
		}
		
		int value = arr[index];
		for (int i = 1; i <= value; i++){ 		//run value times everytime
			
			int next = index + i;
			
			if (!visited[next]){
				q.push({next, cnt + 1});	//counter goes up by 1 b/c we want to know how many times it run
				visited[next] = 1;
			}
		}
	}
	cout << -1;
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	bfs();
	
	return 0;	
}

