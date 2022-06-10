#include <iostream>

using namespace std;

long long dp[1000001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	long long N, index;
		
	cin >> N;
	
	if (N < 0){
		index = N * (-1);
	}
	else{
		index = N;
	}
	
	//if it's 0
	if (index == 0){
		cout << 0 << endl;
		cout << 0;
		return 0;
	}
	
	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= index; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}
	dp[index] = dp[index] % 1000000000;
	
	if (N < 0){
		//if - and even, it's negative (pattern that we can find from negative numbers)
		if (index % 2 == 0){
			cout << -1 << endl;
			cout << dp[index];
			return 0;
		}
	}
	
	cout << 1 << endl;
	cout << dp[index];
	return 0;
	
}
















