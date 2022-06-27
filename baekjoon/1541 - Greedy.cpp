//https://cocoon1787.tistory.com/209
#include <iostream>
#include <string>

#define endl "\n"

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	string str;
	cin >> str;
	
	int len = str.length();
	bool isMinus = false;
	int tmp = 0;
	int sum = 0;
	
	for (int i = 0; i <= len; i++){
		if (str[i] == '-' || str[i] == '+' || i == len){
			if (isMinus == false){
				sum += tmp;
				tmp = 0;
			}
			//when isMinus is true
			else{
				sum -= tmp;
				tmp = 0;
			}
			
			if (str[i] == '-') isMinus = true;
			
		}
		//store number
		else{
			tmp *= 10;
			tmp += str[i] - '0';	//char -> int
		}
	}
	
	cout << sum;
	
	return 0;
}












