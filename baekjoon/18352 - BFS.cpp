#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"
#define MAX 1000001

using namespace std;

int N, M, K, X, mx = 0;
vector<int> v[MAX];
vector<int> result;
queue<int> q;
bool visited[MAX];
int ans[MAX];

void bfs(int start){
	
	q.push(start);
	visited[start] = true;
	ans[start] = 0;
	
	while(!q.empty()){
		
		//current element
		int curr = q.front();
		q.pop();
	
		if (K == ans[curr]){
			result.push_back(curr);
		}
		
		//next elements
		for (int i = 0; i < v[curr].size(); i++){
			
			if (visited[v[curr][i]] == false){
				
				visited[v[curr][i]] = true;
				ans[v[curr][i]] = ans[curr] + 1;
				q.push(v[curr][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++){
		int input1, input2;
		cin >> input1 >> input2;
		
		v[input1].push_back(input2);
	}

	bfs(X);

	if (result.empty()) cout << -1;
	
	sort(result.begin(), result.end());
	for (auto a : result){
		cout << a << endl;
	}

}










