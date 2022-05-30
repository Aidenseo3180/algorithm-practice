#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ans;
    
    vector<int> cnt = {0,0,0};
    vector<vector<int>> input = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    
    for (int i = 0; i < answers.size(); i++){
    	if (input[0][i % input[0].size()] == answers[i]) cnt[0]++;
    	if (input[1][i % input[1].size()] == answers[i]) cnt[1]++;
     	if (input[2][i % input[2].size()] == answers[i]) cnt[2]++;
	}
	
    int mx = *max_element(cnt.begin(), cnt.end());

    for (int i = 0; i < 3; i++){
    	if (mx == cnt[i]) ans.push_back(i + 1);
	}
    
    return ans;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> a = {1,2,3,4,5};
	vector<int> b = {1,3,2,4,2};

	vector<int> result1 = solution(a);
	vector<int> result2 = solution(b);

	for (int i = 0; i < result1.size(); i++){
		cout << result1[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < result2.size(); i++){
		cout << result2[i] << " ";
	}
	cout << endl;
}

