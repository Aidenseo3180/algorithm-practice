#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int solution(vector<int> nums){
    unordered_set<int> st = {nums.begin(), nums.end()};
    
    return min(st.size(), nums.size()/2);
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> v1 = {3,1,2,3};
	vector<int> v2 = {3,3,3,2,2,4};
	vector<int> v3 = {3,3,3,2,2,2};
	
	cout << solution(v1) << endl;
	cout << solution(v2) << endl;
	cout << solution(v3);
}

