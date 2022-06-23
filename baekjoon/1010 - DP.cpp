//https://codejin.tistory.com/m/172

#include <iostream>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;	
	
	//nCr = starting from n/r, reduce both n and r by 1 
	while(t--){
		int answer = 1;
		int temp = 1;
		
		int r, n;
		cin >> r >> n;
		for (int i = n; i > n - r; i--){
			answer *= i;
			answer /= temp++;
		}
		
		cout << answer << endl;	
	}
	
	return 0;
}












