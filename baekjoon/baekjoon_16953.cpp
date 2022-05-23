#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;
long long cnt;
long long result = 10000;


void dfs(long long A, long long B, long long cnt){
	
	if (cnt > result){
		return;
	}
	
	if (A == B){
		result = min(result, cnt);
		return;
	}
	
	//get rid of unncessary calculations
	if (A > B){
		return;
	}
	
	dfs(A*10 + 1, B, cnt + 1);
	dfs(A * 2, B, cnt + 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	dfs(A, B, 1);

	if (result == 10000)
		cout << -1;
	else
		cout << result;
	
}

