#include <iostream>
#include <vector>

using namespace std;

int main(){
	//ios_base::sync_with_stdio(0);	
	//cin.tie(0);

	int n, k, input, m;
	cin >> n >> k;
	
	vector<int> arr;
	
	for (int i = 0; i < n; i++){
		cin >> input;
		arr.push_back(input);
	}
	
	int count = 0;
	for (int i = n-1; i >= 0; i--){
		count = count + k/arr[i];
		k = k%arr[i];	//4700 % 1000 = 700
		
		if (k == 0) break;
	}
	cout << count;
	
	return 0;	
}






