#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];	//inputs
int visited[8];
int result[8];

void dfs(int depth){
	
	if (depth == M){
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	
	int ov = 0;	//reset ov 
	
	for (int i = 0; i < N; i++){
		
		if (!visited[i] && ov != arr[i]){	//if haven't visited && no overlap
		
			result[depth] = arr[i];			
			ov = arr[i];					//for checking overlap (compare with one element before)
			visited[i] = 1;
			dfs(depth + 1);
			visited[i] = 0;					//backtracking
			
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

