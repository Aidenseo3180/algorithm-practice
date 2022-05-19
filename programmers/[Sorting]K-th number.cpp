#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    for (int i = 0; i < commands.size(); i++){	//for num of commands times
    	
    	for (int j = commands[i][0]; j <= commands[i][1]; j++){	//for i to j of each command
    		temp.push_back(array[j - 1]);
		}
		
		sort(temp.begin(), temp.end());	//sort
    	
    	answer.push_back(temp[commands[i][2] - 1]);	//now find temp at k
    	temp.clear();
	}
    
    
    return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> s = {1, 5, 2, 6, 3, 7, 4};
	vector<vector<int>> a = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
	
	vector<int> ans;
	ans = solution(s,a);
	
	cout << "[";
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if (i != ans.size() - 1) cout << ", ";
	}
	cout << "]";
	
}

