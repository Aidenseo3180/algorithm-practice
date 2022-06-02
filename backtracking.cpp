#include <iostream>

using namespace std;

int N, M;	//length, max num
int arr[51];
int visited[51];

void dfs(int depth, int cnt){
	
	if (depth == 3){
		for (int i = 0; i < N; i++){
			cout << arr[i] <<  " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = cnt; i <= M; i++){
		
		if (!visited[i]){
			arr[depth] = i;
			visited[i] = 1;
			dfs(depth + 1, i);	//i + 1 also works (has less recursion). But i works better for 중복순열. 그냥 수열은 i + 1 괜찮, 하지만 중복순열과 순열 둘다 i가 되니까 그냥
			//이렇게 쓴 것 
			visited[i] = 0;
		}
	}
}


int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
		
	cin >> N >> M;	//3 5
	dfs(0, 1);

}


