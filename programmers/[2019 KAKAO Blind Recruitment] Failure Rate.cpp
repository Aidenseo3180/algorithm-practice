#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

bool sortByFirst(const pair<double, int> &a, const pair<double, int> &b){
	
	if (a.first == b.first)	//if values are the same, compare index
		return a.second < b.second;
	
	return (a.first > b.first);		
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<double, int>> failRate;	//failRate, int
    double next = stages.size();
    int cnt = 0;
    
    for (int i = 1; i <= N; i++){
		for (int j = 0; j < stages.size(); j++){
			
			//if fail
			if (stages[j] == i)
				cnt++;
		}
        if (cnt == 0){	//if no one fails, manually it it to 0
            failRate.push_back({0, i});
        }
		else failRate.push_back({cnt/next, i}) ;
		next -= cnt;
		cnt = 0;	//reset
	}
    
    sort(failRate.begin(), failRate.end(), sortByFirst);	//sort in ascending order
    
    for (int i = 0; i < N; i++)
    	answer.push_back(failRate[i].second);
    
    return answer;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> s1 = {2, 1, 2, 6, 2, 4, 3, 3};
	vector<int> s2 = {4,4,4,4,4};
	
	vector<int> sss1 = solution(5, s1);
	vector<int> sss2 = solution(4, s2);

	for (int i = 0; i < sss1.size(); i++)
		cout << sss1[i] << " ";
	cout << endl;
	
	for (int i = 0; i < sss2.size(); i++)
		cout << sss2[i] << " ";
	cout << endl;
}














