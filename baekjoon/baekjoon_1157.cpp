#include <iostream>
#include <string>

using namespace std;

string str;
int max_cnt = 0;
int arr[26];

void counter(char x){
	
	//lower the letter & subtract 97 to set it's base to 0 (a = 97 in ascii, so 0 ~ 25 is the same as a ~ z)
	arr[int(tolower(x)) - 97] += 1;
	
}

int main(void){
	ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> str;
	
	for (int i = 0; i < str.length(); i++){
		counter(str[i]);
	}
	
	char ans;
	//find max
	for (int i = 0; i < 26; i++){
		if (arr[i] > max_cnt){
			max_cnt = arr[i];
			ans = i;
		}
	}
	
	for (int i = 0; i < 26; i++){
		//check if it's the same as max, but not from the same index
		if (arr[i] == max_cnt && i != ans){
			cout << '?';
			return 0;
		}
	}

	cout << char(toupper(ans + 97));

	return 0;	
}



















