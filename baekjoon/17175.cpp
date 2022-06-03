#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	
	//fabonacci bottom-up, 
	int dp[51];
		
	dp[0] = 1;
	dp[1] = 1;
	
	for(int i=2; i<=n; i++){
		dp[i] = (1 + dp[i-2] + dp[i-1]) % 1000000007;	//+1 bc it calls itself in the beginning (in normal fibonacci, + 1 doesn't exist here)
	}
	
	cout << dp[n];
	
	return 0;
}




