#include <iostream>

#define endl "\n"

using namespace std;

//memorization
long long save[101];

long long recursion(int index){
	
	if (index == 0) return 1;
	if (index == 1) return 1;
	if (index == 2) return 1;
	
	//if hasn't saved
	if (save[index] == 0){
		save[index] = recursion(index - 2) + recursion(index - 3);
	}

	return save[index];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T, input;
	cin >> T;
	
	while(T--){
		cin >> input;	
		cout << recursion(input - 1) << endl;	//since input is 1 ~ 100, -1 for 0th indexing
	}
	
}










