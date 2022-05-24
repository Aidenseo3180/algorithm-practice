#include <iostream>

using namespace std;

int T, A, B;
int N, M;

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> T;
	
	while(T--){
		cin >> N >> M;	
		
		for (int i = 0; i < M; i++){
			cin >> A >> B;
		}
		
		cout << N-1 << "\n";
	}

}

