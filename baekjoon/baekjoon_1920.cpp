#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[100001];

void binarySearch(int target){
	int left = 0, right = N-1;
	
	while(left <= right){
		
		int mid = (left + right)/2;

		if (arr[mid] == target){
			cout << 1 << "\n";
			return;
		}
		
		else if (arr[mid] > target){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << 0 << "\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	sort(arr, arr + N);	

	cin >> M;
	
	int input;
	for (int i = 0; i < M; i++){
		cin >> input;
		binarySearch(input);
	}

}

	


