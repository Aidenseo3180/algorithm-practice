#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
#define INF 99999

using namespace std;

int a, b, N, M, min_num = INF;
vector<int> v[10001];
int visited[10001];
int cnt[10001];

void bfs(int start){
	queue<int> q;
	q.push(start);
	cnt[start] = 0;
	visited[start] = 1;
	
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		
		//if reaches the goal, check min value
		if (curr == b){
			if (cnt[curr] < min_num && cnt[curr] < N) //cnt can't be bigger than total number of letters (if N = 4, cnt must be < 4)
				min_num = cnt[curr];
		}
		
		for (int i = 0; i < v[curr].size(); i++){
			int next = v[curr][i];
			
			
			if (!visited[next]){
				visited[next] = 1;	
				cnt[next] = cnt[curr] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++){
		int input1, input2;
		cin >> input1 >> input2;
		
		v[input1].push_back(input2);	//current, {next, cost}
		v[input2].push_back(input1);
	}
	
	bfs(a);	

	if (min_num == INF) cout << -1;
	else cout << min_num;
}










