//problem : https://www.acmicpc.net/problem/2839
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int N;
int main(){
	
	cin >> N;
	int arr[N];
	int sum = 0;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		arr[i] = arr[i] + arr[i-1];
		sum += arr[i];
	}
	cout << sum << endl;
	
	
	
	/*
	cin >> N;
	int count = 0;	//count
	while (N >= 0){
		if (N % 5 == 0){	//check if %5 = 0, 
			count += N/5;
			cout << count << endl;
			return 0;
		}
		N = N - 3;	//if it cant be divided by 5, then -3kg
		count++;
	}	
	cout << -1 << endl;
	*/
}
