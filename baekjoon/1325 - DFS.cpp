#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define endl "\n"

using namespace std;

int N, M;	//N : number of computers, M : number of connections
int cnt;
vector<int> v[10001];
bool visited[10001];

void dfs(int x){

	visited[x] = true;
	
	for (int i = 0; i < v[x].size(); i++){	//search connected copmuters
		
		int next = v[x][i];	
		
		if (visited[next] == false){
			cnt++;		//cnt everytime it finds connectable computers
			dfs(next);	
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	//----------input-----------
	cin >> N >> M;

	for (int i = 0; i < M; i++){
		int node1, node2;
		cin >> node1 >> node2;
		
		v[node2].push_back(node1);	//since the uuestion is asking for how many computers can 2nd computer hack, connection goes one way
	}

	//----------algorithm--------
	int max_cnt = 0;
	vector<int> result;
	
	//goes from 1 ~ N number of computers
	for (int i = 1; i <= N; i++){
		memset(visited, false, sizeof(visited));
		cnt = 0;
		
		dfs(i);
		
		//if == max_cnt, add as answer
		if (max_cnt == cnt){
			result.push_back(i);
		}
		else if (max_cnt < cnt){
			max_cnt = cnt;			//update max
			result.clear();			//clear all the answers b/c we just found bigger one
			result.push_back(i);
		}
		
	}
	
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}

	return 0;	
}



















