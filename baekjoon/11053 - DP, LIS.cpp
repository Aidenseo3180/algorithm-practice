#include <iostream>
#include <vector>
#include <algorithm> 

#define endl "\n"

using namespace std;

int dp[1001];
int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	
	fill(dp + 1, dp + 1001, 1);
	
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			if (arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	int answer = 0;
	for (int i = 1; i <= N; i++){
		answer = max(answer, dp[i]);
	}
	
	cout << answer;
	
}

//Warning : you can find the length, but you can't find the actual, accurate elements
//ex. when the combination is {1,3,6,7}, the actual answer can be {1,2,6,7}. So, the length is always correct, but the elements are not (you have to use stacks/different techniques)






