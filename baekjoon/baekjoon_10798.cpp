#include <iostream>

using namespace std;

char arr[5][16];

int main(){
	
	for (int i = 0; i < 5; i++){
		cin >> arr[i];
	}
	
	for (int j = 0; j < 15; j++){
		for (int i = 0; i < 5; i++){
			if (arr[i][j] != '\0'){
				cout << arr[i][j];
			}
		}
	}
	
}
