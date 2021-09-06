//website : https://www.acmicpc.net/problem/1463
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int MAX = 1000001;
int dp[MAX];

int func(int n){
	if (n==1)return 0;	//if it's 1, print 0
	if (dp[n] != -1) return dp[n];	//if already calculated
	
	int result = func(n-1) + 1;	//10-1 = 9, func(9) runs through
	//func(3-1) runs (so basically another func runs while func(3) is running)
	//+1 is the count, as func goes on, we add +1 to the count
	if (n%3 == 0) result = min(result, func(n/3)+1);	//since 9%3 = 0, this works. func(3) runs
	//3%3 = 0, so this runs again (func(1)). 
	if (n%2 == 0) result = min(result, func(n/2)+1);	
	//1. 10%2 = 0, so this runs as well.
	//but since this line takes longer time than n%3, and since we're looking for min, the n%3 becomes the answer
	
	dp[n] = result;
	return result;
}

int main(){
	int input;
	cin >> input;
	fill(dp, dp+MAX, -1);	//dp[0] + MAX (until the end)
	//when something's inside dp, it's no longer -1
	cout << func(input);
	
	return 0;
}



