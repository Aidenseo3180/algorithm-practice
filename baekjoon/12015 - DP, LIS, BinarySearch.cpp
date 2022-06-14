#include <iostream>
#include <algorithm> 

#define endl "\n"

using namespace std;

int arr[1000001];
int lis[1000001];

int binarysearch(int left, int right, int target){
	
	int mid;
	
	//find target = arr[i] that will go into dp array w/ binary search method
	
	while(left < right){
		mid = (left + right) / 2;	//find mid point
		
		if (lis[mid] < target){
			left = mid + 1;
		}
		else{
			right = mid;
		}
	}
	return right;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	lis[0] = arr[0];	//initialize
	int j = 0;	//for dp
	int i = 1;	//for arr (start from 1 bc we alrdy used arr[0] & it's unnecessary to use the first element since it's length will be 1 anyways)
	
	while(i < N){
		//if dp's last element < arr[i], put it in the end of dp
		if (lis[j] < arr[i]){
			lis[j + 1] = arr[i];
			j += 1;
		}
		//if arr[i] is smaller, find where we should put it w/ binary search method
		else{
			int idx = binarysearch(0, j, arr[i]);
			lis[idx] = arr[i];
		}
		i += 1;
	}
	
	cout << j + 1;

	return 0;
}








