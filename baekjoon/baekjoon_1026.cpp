#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){


	int n, input;
	cin >> n;
	
	vector<int> arrA, arrB;
	for (int i = 0; i < n; i++){
		cin >> input;
		arrA.push_back(input);
	}
	
	for (int i = 0; i < n; i++){
		cin >> input;
		arrB.push_back(input);
	}
	
	sort(arrA.begin(), arrA.end());	//sort A
	
	vector<int> det(n,0);	//check if the array has been used
	
	int result = 0;
	for (int i = 0; i < n; i++){	//A
		int temp = 0;
		int index = 0;
		for (int j = 0; j < n; j++){	//B
			if (temp < arrB[j] && det[j] == 0){
				temp = arrB[j];
				index = j;
			}
		}
		result += arrA[i]*arrB[index];
		//cout << result << "\n";
		det[index] = 1;		//put 1 to used B array
	}
	
	cout << result;
	
	return 0;	
}






