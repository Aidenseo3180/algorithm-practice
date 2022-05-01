#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string arr[3][4];
	
	for (int i = 0; i < 3; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	
	//do : 0(1) 1(3) - A
	//ge : 0(2) 1(2) - B
	//ger : 0(3) 1(1) - C
	//yut : 0(4) - D
	//mo : 1(4) - E
	
	int count = 0;	//number of 1s
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++){
			if (arr[i][j] == "1"){
				count++;
			}
		}
		if (count == 0){
			cout << "D" << endl;
		}
		else if (count == 1){
			cout << "C" << endl;
		}
		else if (count == 2){
			cout << "B" << endl;
		}
		else if (count == 3){
			cout << "A" << endl;
		}
		else{
			cout << "E" << endl;
		}
		
		count = 0;
	}
	
}
