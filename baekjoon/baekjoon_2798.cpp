#include <iostream>

using namespace std;

int N;
long int M;
int arr[101];
long int sum = 0;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 	cin >> N >> M;
 	
 	for (int i = 0; i < N; i++){
 		cin >> arr[i];
 		sum += arr[i];
	}
 	
 	//set min to M
 	int min = M;
 	int result = 0;
 	int ans;
 	int save;
 	for (int i = 0; i < N; i++){
 		for (int j = 0; j < N; j++){
 			if (j != i){
				for (int k = 0; k < N; k++){
 					if ( k != j && k != i){
 						ans = arr[i] + arr[j] + arr[k];
 						//find the difference
 						result = M - ans;
 						//lowest difference = highest, so
 						if (result < min && result >= 0){
 							min = result;
 							save = ans;
						}
							
					}	
				}
			
			}
		}
	}
	
	cout << save;
	
}










