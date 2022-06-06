#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	long long arr[82];
	
	arr[1] = 1;
	arr[2] = 1;
	
	for (int i = 3; i <= 80; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	
	int N;
	cin >> N;
	
	if (N == 1) cout << 4;
	else if (N == 2) cout << 6;
	else{
		cout << arr[N] * 2 + (arr[N - 1] + arr[N])*2;
	}
}	

