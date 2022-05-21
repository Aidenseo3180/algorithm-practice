#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10001];	//store values

int visited[10001];	
int ans[10001];

void dfs( int depth ){
	
	if (depth == M){
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
		
	for (int i = 0; i < N; i++){
		
		if (!visited[i]){
			visited[i] = 1;
			ans[depth] = arr[i];
			dfs(depth + 1);
			visited[i] = 0;
		}
	}
}


int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	sort(arr, arr + N);
	
	dfs(0);
	
}

