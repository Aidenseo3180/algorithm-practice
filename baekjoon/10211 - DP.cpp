#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	//number of test cases
	int T;
	cin >> T;
	
	while(T--){
		int N;
		cin >> N;	
		
		int arr[N];
		int dp[N];
		
		for (int i = 0; i < N; i++){
			cin >> arr[i];
		}
		
		int max_val = -1e9;
		int ans = 0;
		
		for (int i = 0; i < N; ++i){
			//dp[i] is maximum value at i. That means "dp[i] = dp[i-1] + current value"
			//so, in order to get the biggest value, compare dp[i-1] and 0 to decide if we should add onto dp[i-1], or start fresh from 0
			dp[i] = max(0, dp[i - 1]) + arr[i];
			
			max_val = max(max_val, dp[i]);
		}
		
		cout << max_val << endl;
		
	}

	return 0;
}












