#include <iostream>

#define endl "\n"

using namespace std;

int arr[1000001];

int solution(int x){
	
	if (x == 1) return 1;
	if (x == 2) return 2;
	
	if (arr[x] == 0){
		arr[x] = solution(x - 1) + solution(x - 2);
	}
	
	return arr[x] % 15746;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	cout << solution(N);
	
}










