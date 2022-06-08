#include <iostream>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	long long arr[31][31] = {0, };
	arr[1][1] = 1;
	arr[2][1] = 1;
	arr[2][2] = 1;
	
	//bottom-up
	for (int i = 3; i <= 30; i++){
		for (int j = 1; j <= i; j++){
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];	
		}
	}

	int R,C,W;
	cin >> R >> C >> W;
	
	int cnt = 0;
	long long sum = 0;
	for (int i = R; i < W + R; i++){
		for (int j = C; j <= C + cnt; j++){
			//cout << "i : " << i << " j : " << j << " = " << arr[i][j] << endl;
			sum += arr[i][j];
		}
		cnt++;
	}
	
	cout << sum;
}

