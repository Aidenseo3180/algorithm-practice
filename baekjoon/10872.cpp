#include <iostream>

using namespace std;

long long recursion(int value){
	
	if (value == 0) return 1;
	if (value == 1) return 1;
	
	return value * recursion(value - 1);
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int x;
	cin >> x;
	
	cout << recursion(x);

}


