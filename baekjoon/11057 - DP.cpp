#include <iostream>

using namespace std;

int dp[1001][10] = {0,};

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++){	//0 ~ 9, so 10
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 10; j++){
			if (j == 0){
				dp[i][0] = 1;
				continue;
			}
			
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 10007;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++){
		sum += dp[n][i];
	}
	
	cout << sum % 10007;
	
	return 0;	
}





