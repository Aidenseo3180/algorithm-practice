#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    //linked list
	vector<vector<int>> graph (n + 1);	//+1 bc we start from 1th index, not 0th
	vector<bool> visited (n + 1, false);
	vector<int> cnt(n + 1, 0);
	queue<int> q;

    for (int i = 0; i < edge.size(); i++){
    	//since it goes both direction,
    	graph[edge[i][0]].push_back(edge[i][1]);
    	graph[edge[i][1]].push_back(edge[i][0]);
	}
	
	q.push(1);	//starts at 1
	visited[1] = true;
	
	while(!q.empty()){
		int node = q.front();	
		q.pop();
		
		//go through all the connected nodes
		for (int i = 0; i < graph[node].size(); i++){
			//if not already visited
			if (visited[graph[node][i]] == false){			
				q.push(graph[node][i]);
				visited[graph[node][i]] = true;
				cnt[graph[node][i]] = cnt[node] + 1;	//steps to go to current node + 1 = steps to go to next node
			}
		}
	}
	
	sort(cnt.begin(), cnt.end(), greater<int>());
	
	for (auto a : cnt){
		if (cnt[0] != a) break;
		answer++;
	}
    
    return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	vector<vector<int>> v = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
	
	cout << solution(6, v);


}










