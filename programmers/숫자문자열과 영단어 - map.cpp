#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string str) {
    
    unordered_map<string, string> map = {
		{"zero", "0"}, 
		{"one", "1"}, 
		{"two", "2"}, 
		{"three", "3"}, 
		{"four", "4"}, 
		{"five", "5"}, 
		{"six", "6"}, 
		{"seven", "7"}, 
		{"eight", "8"}, 
		{"nine", "9"}
	};
    
    string temp = "";
	string ans = "";
	for (int i = 0; i < str.length(); i++){
		
		if (isdigit(str[i])){
			ans += str[i];
			continue;
		}
		
		temp += str[i];
		
		//when it does exist
		if (map.find(temp) != map.end()){
			auto search = map.find(temp);
			ans += search -> second;
			temp = "";
		}
	}
	//convert to int
    return stoi(ans);
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
		
	cout << solution("one4seveneight") << "\n";
	cout << solution("23four5six7") << "\n";
	cout << solution("2three45sixseven") << "\n";
	cout << solution("123") << "\n";

}
