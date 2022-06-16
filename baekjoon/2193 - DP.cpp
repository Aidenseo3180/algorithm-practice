#include <iostream>

#define endl "\n"

using namespace std;

long long arr[91] = {0,};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	arr[1] = 1;
	arr[2] = 1;
	
	for (int i = 3; i <= N; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	
	cout << arr[N];

	return 0;
}








