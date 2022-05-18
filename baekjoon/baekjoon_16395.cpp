#include <iostream>

using namespace std;

int N, K;
int arr[31][31];

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	//start from 1
	arr[1][1] = 1;
	arr[2][1] = 1;
	arr[2][2] = 1;
	
	//since arr[0].. or arr[2][0] is 0 (bascially everything else is 0, we get 1 as it adds up with 0 + 1)
	
	//calculation ex) arr[3][2] = arr[2][2] + arr[2][1]
	for (int i = 3; i <= N; i++){
		for (int j = 1; j <= N; j++){
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	
	cout << arr[N][K];
	
	return 0;	
}


