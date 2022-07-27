//https://codingwell.tistory.com/28
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    
    //save index to queue
    for (int i = 0; i < priorities.size(); i++){
    	q.push(i);
	}
    
    int max_val = *max_element(priorities.begin(), priorities.end());    
    while(!q.empty()){
    	//first element from queue
    	int index = q.front();
    	q.pop();
    	
    	//compare w/ max_prioritiy
    	if (priorities[index] != max_val){
    		q.push(index);		//if not the same, push to back
		}
    	else{
    		answer++;
    		if (index == location) return answer;	//if that's what we wanted, exit right away
    		
    		priorities[index] = 0;	//set priority to 0 b/c we've already used it
    		max_val = *max_element(priorities.begin(), priorities.end());	//then find next max value
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<int> v = {1,1,9,1,1,1};
	cout << solution(v, 0);
	
	return 0;
}
















