//https://yabmoons.tistory.com/131
#include <iostream>
#include <algorithm>

#define endl "\n"

using namespace std;

int max_val = -1;
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
		
		dp[i] = 1;	//initialize all dp to 1
	}

	for (int i = 2; i <= N; i++){
		//try all prev. values
		for (int j = 1; j < i; j++){
			if (arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);	//compare current dp w/ other dp + 1, select higher one
			}
		}
		
		if (dp[i] > max_val) max_val = dp[i];
	}	

	cout << max_val;

	return 0;	
}



















