#include <iostream>

#define endl "\n"

using namespace std;

long long arr[10000001];

long long solution(int index){
	
	if (index == 1) return 1;	//1
	if (index == 2) return 2;	//1 + 1, 2
	if (index == 3) return 4;	//1 + 1 + 1, 2 + 1, 1 + 2, 3
	
	if (arr[index] == 0){
		arr[index] = solution(index - 1) + solution(index - 2) + solution(index - 3);
	}
	return arr[index] % 1000000009;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while(T--){
		int input;
		cin >> input;	
		cout << solution(input) << endl;
	}	
}










