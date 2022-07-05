//https://yabmoons.tistory.com/491

#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int coin[101];
int dp[10001];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++){
		cin >> coin[i];
	}
	
	dp[0] = 1;	//1 way to get k = 0	
	
	for (int i = 1; i <= n; i++){
		for (int j = coin[i]; j <= k; j++){
			dp[j] = dp[j] + dp[j - coin[i]];	//start from dp[0] (bc j = coin[i], & dp[j - coin[i]] = 0 in the beginning)
		}
	}
	
	/*Can also do : 
	for (int i = 1; i <= n; i++){
		cin >> now;
		
		for (int j = now; j <= k; j++){
			dp[j] = dp[j] + dp[j - now];
		}
	}
	*/
	
	cout << dp[k];
	
	return 0;	
}





