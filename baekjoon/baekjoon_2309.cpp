#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int sum = 0;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	for (int i = 0; i < 9; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort (arr, arr + 9);
	
	for  (int i = 0; i < 8; i++){
		for (int j = 1; j < 9; j++){
			//even if i and j are the same, it doesn't matter
			//if we've found that sum - 2 numbers = 100,
			if (sum - arr[i] - arr[j] == 100){
				for (int k = 0; k < 9; k++){
					if (k != i && k != j){
						cout << arr[k] << "\n";
					}
				}
				return 0;
			}
		}	
	}
	
	

}










