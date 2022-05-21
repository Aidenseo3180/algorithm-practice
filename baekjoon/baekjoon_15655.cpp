#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10001];	//store values

int visited[10001];	
int ans[10001];

void dfs( int depth, int cnt){
	
	if (depth == M){
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = cnt; i < N; i++){
		
		//cout << "depth : " << depth << " - " << i << "\n";
		
		if (!visited[i]){

			ans[depth] = arr[i];
			dfs(depth + 1, i + 1);	//increment cnt (i) by 1

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
	
	dfs(0, 0);
	
}

