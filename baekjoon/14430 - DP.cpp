#include <iostream>
#include <algorithm>

#define endl "\n"

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;
	
	int arr[301][301] = {0,};
	int dp[301][301] = {0,};	//maximum value in that location
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			//max num if you go down from current location
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			//max num if you go right from current location
			dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
		}
	}
	
	cout << dp[N][M];
	
}
















