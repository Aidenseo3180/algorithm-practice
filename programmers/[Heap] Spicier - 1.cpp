#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
       
    //min heap (lowest comes on top)
    priority_queue<int, vector<int>, greater<int>> pq (scoville.begin(), scoville.end());	//index, STL container, comparator
    
    while(pq.top() <= K && pq.size() > 1){
    	int first = pq.top();
    	pq.pop();
    	int second = pq.top();
    	pq.pop();
    	
    	pq.push(first + (second * 2));
    	answer++;
	}
    
    //if still <= K after processing, -1
    if (pq.top() <= K){
    	return -1;
	}
    
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	
	vector<int> s = {1, 2, 3, 9, 10, 12};
	
	cout << solution(s, 7);

}










