#include <iostream>

#define endl "\n"

using namespace std;

long long arr[35] = {0,};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	
	//bottom - up 
	arr[0] = 1;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < i; j++){
			arr[i] += arr[j] * 	arr[i - j - 1];
		}
	}

	cout << arr[N];

	return 0;
}








