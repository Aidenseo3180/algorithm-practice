//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

int C, N, total;
int index = 0;
int arr[1001][1001];

void calculate(int t, int NN){
	double count = 0;
	double avg = t / NN;

	for (int j = 0; j < NN; j++){
		//cout << arr[index][j] << "\n";
		if (arr[index][j] > avg){
			count++;
		}
	}
	
	//increment index everytime
	index++;
	cout << fixed << setprecision(3) << count / NN * 100 << "%\n";
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> C;

	for (int i = 0; i < C; i++){
		//since we take N everytime, put it here
		cin >> N;
		total = 0;
		
		//and take all the values here
		for (int j = 0; j < N; j++){
			cin >> arr[i][j];
			total += arr[i][j];
		}
		
		calculate(total, N);
	}

	return 0;
}



