#include <iostream>

#define endl "\n"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T; 
	
	//1 ~ 10
	int arr[11];
	arr[1] = 1;	//1
	arr[2] = 2;	//1 + 1, 2
	arr[3] = 4;	//1 + 1 + 1, 2 + 1, 1 + 2, 3
	
	for (int i = 4; i < 11; i++){
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}
	
	while(T--){
		int input;
		cin >> input;
		cout << arr[input] << endl;
	}
	
}










