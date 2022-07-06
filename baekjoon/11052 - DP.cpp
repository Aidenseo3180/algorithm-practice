//https://yabmoons.tistory.com/23
#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int arr[10001];
int dp[10001];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}

	dp[0] = 0;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= i; j++){
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[n];

	return 0;	
}





