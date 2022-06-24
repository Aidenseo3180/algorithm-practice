#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	int arr[N][M];
	int dp[N][M];
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> arr[i][j];
			dp[i][j] = -1e9;
		}
	}
	
	dp[0][0] = arr[0][0];
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			
			//max( current + next vs. next value). If next value > current + next value, replace w/ next value
			//then, compare old dp vs new dp at that point. If new dp is higher, replace 
			if (i + 1 < N && j + 1 < M) dp[i + 1][j + 1] = max(max(dp[i][j] + arr[i + 1][j + 1], arr[i + 1][j + 1]), dp[i + 1][j + 1]);
			if (i + 1 < N) dp[i + 1][j] = max(max(dp[i][j] + arr[i + 1][j], arr[i + 1][j]), dp[i + 1][j]);
			if (j + 1 < M) dp[i][j + 1] = max(max(dp[i][j] + arr[i][j + 1], arr[i][j + 1]), dp[i][j + 1]);
			
		}
	}
	
	cout << dp[N - 1][M - 1];
	
	return 0;
}

//explanation :
/*
dp[i][j] = i,j에 있는 최대값
현재 최대값 + 다음 값 vs. 다음 값 비교해서 더 큰거로 바꿈. 
그리고, 먼저 들어있던 dp값과 새로 이번에 계산한 dp값을 비교, 더 큰거로 바꿈 (그래서 처음에 -1e9로 시작. 계속 더 큰 값으로 바꿀거니까)

*/





