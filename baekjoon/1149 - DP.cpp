//https://wooono.tistory.com/418
//https://cryptosalamander.tistory.com/84
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	int cost[N];
	
	cin >> N;
	
	dp[0][0] = 0;	//R
	dp[0][1] = 0;	//G
	dp[0][2] = 0;	//B
	
	for (int i = 1; i <= N; i++){
		cin >> cost[0] >> cost[1] >> cost[2];
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];	
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
	}
	
	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
	
	return 0;	
}





