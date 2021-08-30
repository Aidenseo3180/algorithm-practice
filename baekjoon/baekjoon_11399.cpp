//problem : https://www.acmicpc.net/problem/11399
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
	
	cin >> N;
	int arr[N];
	int sum = 0;
	
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int nn = sizeof(arr)/sizeof(arr[0]);
	
	sort(arr, arr+nn);
	for(int j = 0; j < N; j++){
		arr[j] = arr[j] + arr[j-1];
		sum += arr[j];
	}	
	cout << sum << endl;

	return 0;
}
