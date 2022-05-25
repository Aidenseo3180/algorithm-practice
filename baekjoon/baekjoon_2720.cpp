#include <iostream>

using namespace std;

int T, C;
int Q,D,N,P;

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> T;
	
	while(T--){
		cin >> C;	
		
		C = C;
		Q = (C / 25);
		C -= 25 * Q;	
	
		D = C/ 10;
		C -= 10 * D;	

		N = C / 5;
		C -= 5 * N;
		
		P = C / 1;
		C -= 1 * P;
		
		cout << Q << " " << D << " " << N << " " << P << "\n";
		
	}
}

