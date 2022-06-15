//https://luv-n-interest.tistory.com/1266

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_set>

#define endl "\n"

using namespace std;

vector<int> v;	//input
unordered_set<int> numbers;	//to get rid of overlaps, store ans
bool check[10];
int n, k;

void solution(int cnt, string s){
	//when cnt meets its limit
	if (cnt == k){
		numbers.insert(stoi(s));	//add to set (if overlap exists, only one stays)
		return;
	}
	
	for (int i = 0; i < n; i++){
		if (check[i] == true) continue;
		
		check[i] = true;
		string ans = s;
		
		ans += to_string(v[i]);	//insert next number at the end of string
		solution(cnt + 1, ans);	//recursively add numbers at the end of string
		check[i] = false;		//change the status of i to repeat the process later
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++){
		int input;
		cin >> input;
		v.push_back(input);
	}

	solution(0, "");

	cout << numbers.size();

	return 0;
}








