#include <iostream>

#define endl "\n"

using namespace std;

//not going to use 0th index
int dp[16];	//sum
int time[16];
int value[16];
int N;

int solution(int day){

	//if exceed, means it doesn't meet in time, so give -10000.. so that we can ignore it when finding max
	if (day > N + 1) return -100000;	//+ 1 bc we start from 1, not 0th index

	//if day is N + 1, it is time to leave, so return 0
	if (day == N + 1) return 0;

	if (dp[day] != -1) return dp[day];
	
	//from day = 1, recursively look through solution(2) AND solution(4) + 10.
	//then, check which one is max
	
	int next = time[day];
	
	dp[day] = max(solution(day + 1), solution(day + next) + value[day]);
	return dp[day];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++){
		cin >> time[i] >> value[i];
		dp[i] = -1;
	}

	cout << solution(1) << endl;
	
	//for some reason, day 2 is 45, not 20  (hmm)
	
//	for (int i = 1; i <= N; i++){
//		cout << dp[i] << " ";
//	}
}










