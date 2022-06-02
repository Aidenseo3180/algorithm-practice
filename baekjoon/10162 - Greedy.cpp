#include <iostream>

#define endl "\n"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int T;
	int arr[3] = {0};
	
	cin >> T;
	
	while(1){
		
		if (T >= 300){
			arr[2]++;
			T -= 300;
		}
		else if (T >= 60){
			arr[1]++;
			T -= 60;
		}
		else if (T >= 10){
			arr[0]++;
			T -= 10;
		}
		
		if (T < 10) break;
		
	}
	if (T != 0) cout << -1;
	else cout << arr[2] << " " << arr[1] << " " << arr[0];
	
}










