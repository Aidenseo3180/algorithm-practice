//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int N;
int result = 0;

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N;
	
	for (int i = 1; i <= N; i *= 10){
		result += N - i + 1;
	}
	cout << result;

	return 0;
}



