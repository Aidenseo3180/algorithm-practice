#include <iostream>
#include <string>

using namespace std;

string str;
//ball is in left cup in the beginning
int arr[] = {1, 0, 0};
int temp;

void func(int start, int end){
	temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str;
    
    for (int i = 0; i < str.length(); i++){
    	if (str[i] == 'A'){
    		func(0,1);
		}
		else if (str[i] == 'B'){
			func(1,2);
		}
		else if (str[i] == 'C'){
			func(0,2);
		}	
	}
    
	if (arr[0] == 1) cout << 1;
	else if (arr[1] == 1) cout << 2;
	else if (arr[2] == 1) cout << 3;

}










