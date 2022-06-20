//https://ingyeoking13.tistory.com/247
#include <iostream>

#define MAX 1000 + 1

using namespace std;

long long dp[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	dp[0][0] = 1;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			//since it can only go right, down, down horizontal (ex, if looking for 2,2, we need 1,2 & 2,1 & 1,1)
			
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += dp[i][j - 1];
			
			dp[i][j] %= (int)1e9 + 7;	//avoid having size error, % by 10 ^ 9 + 7
			
			dp[i][j] += dp[i - 1][j - 1];
			
			dp[i][j] %= (int)1e9 + 7;
		}
		
	}
	
	cout << dp[n][m];
	

	return 0;
}








