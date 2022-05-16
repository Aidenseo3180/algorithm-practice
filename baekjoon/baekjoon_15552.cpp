#include <iostream>

using namespace std;

int N;

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	int input1, input2;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> input1 >> input2;
		cout << input1+input2 << "\n";
	}
	
	return 0;	
}


