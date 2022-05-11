#include <iostream>

using namespace std;

int input;
int pos[6] = {500, 100, 50, 10, 5, 1};
int count = 0;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 	cin >> input;
 	
 	input = 1000 - input;
 	
 	for (int i = 0; i < 6; i++){
 		while(input >= pos[i]){
 			input -= pos[i];
 			count++;
 			 			
		}
	 }
 	
 	cout << count;
 
}










