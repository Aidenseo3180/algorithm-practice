#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int dp[501][501] = {0,};
int arr[501][501];

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n; 
	
	//input
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];

	
	//bottom-up
	dp[1][1] = arr[1][1];
	
	for (int i = 2; i <= n; i++){	//when i = 2, j also goes to 2. But since we're calculating both i,j and i,j+1, j goes until i -1
		for(int j = 1; j <= i - 1; j++){
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + arr[i][j + 1]);
		}
	}
	
	int max_val = -1e9;
	for (int i = 1; i <= n; i++){	//find max from the end of the array n
		if (max_val < dp[n][i]) max_val = dp[n][i];
	}
	
	cout << max_val;
	
	return 0;	
}





