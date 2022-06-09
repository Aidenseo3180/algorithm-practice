#include <iostream>
#include <algorithm>

#define endl "\n"

typedef long long ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	int dp[11] = {0,};
	
	dp[1] = 0;
	dp[2] = 1;
	
	for (int i = 3; i <= N; i++){
		dp[i] = dp[i - 1] + (i - 1);	//current = previous + (count - 1)
	}
	
	cout << dp[N];
	
}
















