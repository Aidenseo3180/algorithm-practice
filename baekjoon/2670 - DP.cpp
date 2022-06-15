//https://se-jung-h.tistory.com/entry/BOJC-%EB%B0%B1%EC%A4%80-2670-%EC%97%B0%EC%86%8D%EB%B6%80%EB%B6%84%EC%B5%9C%EB%8C%80%EA%B3%B1

#include <iostream>
#include <cstdio>
#include <algorithm>

#define endl "\n"

using namespace std;

double dp[10001];
double arr[10001];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++){
		scanf("%lf", &arr[i]);
	}
	
	dp[1] = arr[1];
	
	double maxi = 0;
	for (int i = 2; i <= N; i++){
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);	//compare 현재 수 vs. 여태까지 곱해왔던 수 * 현재 수 
		
		maxi = max(maxi, dp[i]);					//find the maximum among dp
	}

	printf("%.3f", maxi);

	return 0;
}








