#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int arr[100000];
int dp[100000];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int max_val = -1e9;
	for (int i = 0; i < n; ++i){	//both ++i and i++ works
		//current max = max( prev. max + current value, current value)
		dp[i] = max(dp[i-1] + arr[i], arr[i]);
		
		//cout << i << " : " << dp[i] << endl;
		if (dp[i] > max_val) max_val = dp[i];
	}
	
	cout << max_val;

	return 0;
}

/*
explanation :
if current value is higher than prev. max + current value, then refresh & set current max as current value!

*/






