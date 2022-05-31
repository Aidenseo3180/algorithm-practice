#include <iostream>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    
    vector<int> time;
    
    for (int i = 0; i < progresses.size(); i++){
    	time.push_back(((99 - progresses[i]) / speeds[i]) + 1);	//days left in each progress 
	}
	
	int start = time[0];	//set to first item of vec. (time takes for first task to be finished)
	ans.push_back(1);		//start from day 1
	for (int i = 1; i < time.size(); i++){ //start from start + 1 index
		
		if (start < time[i]){		//if greater than front value, renew & restart counting
			ans.push_back(1);
			start = time[i];
		}
		else{
			++ans.back();
		}
	}
    
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> a = {93, 30, 55};
	vector<int> b = {1, 30, 5};
	
	vector<int> a1 = {95, 90, 99, 99, 80, 99};
	vector<int> b1 = {1, 1, 1, 1, 1, 1};
	
	vector<int> v = solution(a, b);
	vector<int> v1 = solution(a1, b1);
	
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < v1.size(); i++){
		cout << v1[i] << " ";
	}
	
}










