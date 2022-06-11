#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	double max = 0;
	double sum = 0;
	for (int i = 0; i < N; i++){
		double input;
		cin >> input;
		sum += input;
		if (input > max) max = input;
	}
	
	sum = sum / N;
	cout << (sum/max) * 100;
	
}
















