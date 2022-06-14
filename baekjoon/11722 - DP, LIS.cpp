#include <iostream>
#include <vector>
#include <algorithm> 

#define endl "\n"

using namespace std;

int arr[1001];
int dp[1001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	for (int i = 1; i <= N; i++){
		dp[i] = 1;
		for (int j = 1; j <= i; j++){
			if (arr[i] < arr[j]){
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; i++){
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
}








