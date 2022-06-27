//https://code-kh-studio.tistory.com/9
#include <iostream>
#include <string>
#include <algorithm>

#define endl "\n"

using namespace std;

string str;
int alpha[26] = {0,};	//count num of letters
int err = 0;	//cnt number of letters w/ odd counts
int mid = -1;	//save midpoint

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> str;
	
	for (int i = 0; i < str.length(); i++){
		alpha[str[i] - 'A']++;
	}	
	
	for (int i = 0; i < 26; i++){
		//if odd
		if (alpha[i] % 2 == 1){
			
			alpha[i]--;
			mid = i;
			err++;
			
		}
	}
	
	//if there's more than 1 odd-number letter, then it's not a palindrome
	if (err > 1){
		cout << "I'm Sorry Hansoo";
	}
	else{
		string ans = "";
		string temp = "";		
		
		for (int i = 0; i < 26; i++){
			if (alpha[i] > 0){
				for (int j = 0; j < alpha[i] / 2; j++){
					ans += i + 'A';		//int -> char
				}
			}
		}
		
		temp = ans;
		reverse(temp.begin(), temp.end());	//since it's palindrome, reverse to find the back side of palindrome
		
		//if mid point exists
		if (mid != -1){
			ans += mid + 'A';
		}
		
		cout << ans + temp;
	}
	return 0;
}












