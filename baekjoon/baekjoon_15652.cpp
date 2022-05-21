#include <iostream>

using namespace std;

int N, M;
int arr[9];
int visited[9];

void dfs(int depth, int cnt){	//depth : level, cnt : value

	if (depth == M){
		for (int i = 0; i < M; i++)	{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	//cout << "depth : " << depth << " : "<< cnt << "\n";
	
	for (int i = cnt; i <= N; i++){
			
		arr[depth] = i;
		dfs(depth + 1, cnt);
		
		cnt++;	//after 3rd depth ends, goes back to 2nd, increment cnt
		//after 2nd depth, goes back to 1st, increment cnt
		//so : 2 - 3 -> 1 - 2
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	dfs(0, 1);
	
}

