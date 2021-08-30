//problem : https://www.acmicpc.net/problem/11399
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
	return 0;
}
