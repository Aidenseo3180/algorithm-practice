#include <iostream>
#include <vector>
#include <algorithm> 

#define endl "\n"

using namespace std;

int dp[2001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	vector<int> v(N + 1);
		
	for (int i = 1; i <= N; i++){
		cin >> v[i];
	}

	//LIS, but this time, it's 증가하는 부분수열.  
	for (int i = 1; i <= N; i++){
		dp[i] = v[i];
		for (int j = 1; j <= i; j++){

			if (v[i] > v[j]){
				dp[i] = max(dp[i], dp[j] + v[i]);	//update
			}
		}
	}

	int ans = 1; 
	for (int i = 1; i <= N; i++){
		ans = max(ans, dp[i]);
	}

	cout << ans;
}

/*
LIS explanation : https://yabmoons.tistory.com/87
*/







