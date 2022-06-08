#include <iostream>

#define endl "\n"

using namespace std;

int max(int a, int b){
	if (a > b) return a; return b;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	int arr[10001] = {0, };
	int dp[10001] = {0, };
	cin >> T;
	
	for (int i = 1; i <= T; i++){
		cin >> arr[i];
	}
	
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(max(arr[2] + arr[3], dp[2]), arr[1] + arr[3]);
	
	for (int i = 4; i <= T; i++){	
		dp[i] = max(max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]), dp[i - 1]);
		//cout << dp[i] << " = " << dp[2] << " + " << arr[4] << " vs. " << dp[1] << " + " << arr[3] << " + " << arr[4] << endl;
	}
	
	cout << dp[T];
}

/*explanation :
dp[1] & dp[2] are constant : since they don't go above size of 3 (not allowed to drink 3 in a row)

dp[1] = arr[1]
dp[2] = arr[1] + arr[2]

**with example : 1 2 3 4 5
dp[3] - possible combinations : 1 + 3, 1 + 2, 2 + 3 ---> dp[1] + arr[3], dp[2], arr[2] + arr[3]
	-> find max from these possible combinations

dp[4] = 1 + 3 + 4, 1 + 2 + 4, 2 + 3 ---> dp[1] + arr[3] + arr[4}, dp[2] + arr[4], dp[3] <- since arr[2] + arr[3] is one of the possible combinations of dp[3], you can say this
	-> find max out of these

And from now on, the pattern for dp[4] repeats over and over from other locations --> so, dp[4] pattern = dp[n] pattern

---> PS. actually, dp[3] pattern is the same as dp[4] pattern. So instead of starting at 4, we can just start at 3 and move on with it

more explanation : https://yabmoons.tistory.com/18?category=838244
*/
