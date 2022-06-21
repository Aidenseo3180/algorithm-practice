//https://guiyum.tistory.com/21
//https://yabmoons.tistory.com/137
#include <iostream>

#define mod 9901

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	int dp[100001][3] = {0,};
	
	cin >> N;
	
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	
	for (int i = 2; i <= N; i++){
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
	}
	
	cout << (dp[N][0] + dp[N][1] + dp[N][2]) % mod;
	
	return 0;
}


