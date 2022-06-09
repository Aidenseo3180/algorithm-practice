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
	
	int dp[1001];
	
	//SK : 1, CY : 0
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	
	//bottom-up, stack up from small -> large
	for (int i = 4; i <= N; i++){
		//if dp[i - 1] is won by CY, dp[i] will be it's opposite = SK
		if (dp[i - 1] == 0 || dp[i - 3] == 0){
			dp[i] = 1;	//SK
		}
		else{
			dp[i] = 0;
		}
	}
	
	//answer :
	if (dp[N] == 1) cout << "SK";
	else cout << "CY";
}


//more information : https://yabmoons.tistory.com/581













