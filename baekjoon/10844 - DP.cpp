#include <iostream>

#define endl "\n"
#define limit 1000000000

//typedef long long ll

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	long long arr[101][10] = {0, };
	
	//initial:
	for (int i = 1; i <= 9; i++){
		arr[1][i] = 1;	//put 1~9 to arr[1][1~9]
	}
	
	//number of digits
	for (int i = 2; i <= T; i++){
		//0 ~ 9
		for (int j = 0; j <= 9; j++){
			if (j == 0){
				arr[i][j] = arr[i - 1][j + 1] % limit;
			}
			else if (j == 9){
				arr[i][j] = arr[i - 1][j - 1] % limit;
			}
			else{
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % limit;
			}
		}
	}

	//answer :
	long long sum = 0;
	for (int i = 0; i <= 9; i++){
		sum += arr[T][i];
	}

	cout << sum % limit;
}
















