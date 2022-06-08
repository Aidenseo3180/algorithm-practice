#include <iostream>

#define endl "\n"

using namespace std;

int max(int A, int B){
	if (A > B) return A; return B;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	int arr[301], dp[301];
	for (int i = 1; i <= T; i++){
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	
	for (int i = 4; i <= T; i++){
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		
		cout << dp[i] << " = " << dp[i - 3] << " + " << arr[i - 1] << " + " << arr[i] << " vs. " << dp[i - 2] << " + " << arr[i] << endl;
	}
	
	cout << dp[T];
}

