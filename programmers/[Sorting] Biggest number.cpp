#include <bits/stdc++.h>

using namespace std;

//customize cmp function for sort functions
bool cmp(const string &a, const string &b){	//prevent copy constructor, so faster than (string a, string b)
	//6 + 10 (610) > 10 + 6 (106)
	//since 610 is bigger, sorts in 6, 10 order
	return a + b > b + a;
}

string solution (vector<int> numbers){
	string answer = "";
	
	vector<string> temp;
	for (auto num : numbers)
		temp.push_back(to_string(num));
	
	//sort ascendingly
	sort(temp.begin(), temp.end(), cmp);
	
	if (temp.at(0) == "0") return "0";
	
	for (auto num : temp)
		answer += num;
	return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> v = {6, 10, 2};
	vector<int> v1 = {3, 30, 34, 5, 9};
	
	cout << solution(v) << "\n";
	cout << solution(v1);
}















