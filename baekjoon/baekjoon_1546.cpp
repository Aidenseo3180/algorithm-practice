#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	double result[3];
	double sum = 0;
	double arr[3];	//store input data
	
	int n;
	cin >> n;
	
	for (int aa = 0; aa < n; aa++){
		cin>> arr[aa];	//get user input (n number of times)
	}
	
	double max = arr[0];
	
	for (int i = 0; i<n; i++){	//find max value M
		if (arr[i] > max){
			max = arr[i];
		}
	}
	
	for (int j = 0; j <n; j++){	//get new values with M
		result[j] = (arr[j]/max) * 100;
		sum +=result[j];
	}
	
	sum = sum/n;	//find new avg
	cout << sum << endl;
	
	return 0;
}







