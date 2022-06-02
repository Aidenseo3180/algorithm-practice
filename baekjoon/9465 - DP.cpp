#include <iostream>
#include <algorithm>

#define endl "\n"

#define N 100000

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    
    while(T--){
    	
    	int input;
    	cin >> input;	
    	
    	//2n
    	int dp[2][N];
    	dp[0][0] = dp[1][0] = 0;	//not gonna use, so set to 0
    	
    	for (int i = 1; i <= input; i++){
    		cin >> dp[0][i];
		}
    	
    	for (int i = 1; i <= input; i++){
    		cin >> dp[1][i];
		}
    	
    	//bottom up method
    	for (int i = 2; i <= input; i++){
    		dp[0][i] = dp[0][i] + max(dp[1][i - 1], dp[1][i - 2]);	//current + MAX(diagonal - 1, diagonal - 2)
    		dp[1][i] = dp[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
    	
    	int answer = max(dp[0][input], dp[1][input]);
    	cout << answer << endl;
    	
	}

}
  
  
  
  
  
  
