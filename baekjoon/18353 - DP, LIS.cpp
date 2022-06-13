#include <iostream>
#include <vector>
#include <algorithm> 

#define endl "\n"

using namespace std;

int dp[2001];	//i가 가질 수 있는 최대증가수열의 길이 

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
	
	//since solder with high attack comes front as input, reverse it to mimic ascending order (2,3,5,7..)(since vector starts from index 1)
	reverse(v.begin() + 1, v.end());
	
	//fill dp with 1 (use fill, memset doesn't work for vectors)
	fill(dp + 1, dp + 2001, 1); 
		
	//LIS : 최장증가수열 - 부분적으로 증가하는 수열 중 가장 긴걸 찾음 
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= i; j++){
			//if current 
			if (v[i] > v[j]){ 
				dp[i] = max(dp[i], dp[j] + 1);	
			}
		}
	}
	
	int answer = 0;
	for (int i = 1; i <= N; i++){
		//cout << " i : " << i << " - " << dp[i] << endl;
		answer = max(answer, dp[i]);
	}
	
	cout << N - answer;
   	return 0;

}

/*
LIS explanation :
If you have {10, 20, 10, 30}

i is from 1 ~ 4
when i = 1, since there's no numbers other than 10, dp[1] = 1
when i = 2, since 20 > 10, so dp[2] = dp[1] + 1
when i = 3, since there's no numbers smaller than 10, dp[3] = 1
when i = 4, since there are several numbers less than 30, choose the biggest one(using max) & + 1 it. As a result, dp[4] = dp[2] + 1

*/







