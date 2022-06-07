#include <iostream>
#include <vector>

#define endl "\n"

using namespace std;

long long arr[69] = {0, };

long long koong( int n ){
	
	if (n < 2) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	
	if (arr[n] == 0) arr[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	
	return arr[n];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
	
		int input;
		cin >> input;	
		
		cout << koong(input) << endl;
	}

}

