#include <iostream>

using namespace std;

int N, M;
int arr[9];
int visited[9];

void dfs(int depth, int cnt){	//depth : leve, cnt : value
	if (depth == M){
		for (int i = 0; i < M; i++)	
			cout << arr[i] << " ";

		cout << "\n";
		return;
	}
	
	for (int i = cnt; i <= N; i++){
		
		if (!visited[i]){
			visited[i] = 1;
			arr[depth] = i;
			dfs(depth + 1, i + 1);
			visited[i] = 0;
		}
		
	}
	
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	dfs(0,1);
	
}

