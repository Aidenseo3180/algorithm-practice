#include <iostream>
#include <string>
#include <regex>

using namespace std;

int solution(string s) {

	s = regex_replace(s, regex("zero"), "0");    //replace zero into 0 from s
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");

	int ans = stoi(s);
	return ans;
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
