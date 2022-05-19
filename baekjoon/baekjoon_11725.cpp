#include <iostream>
#include <vector>

using namespace std;

long int N;
vector<int> v[100001];
int visited[100001], parent[100001];

void dfs(int start){
	
	visited[start] = 1;
	
	for (int i = 0; i < v[start].size(); i++){
		//v[start][i] = next connected node
		int x = v[start][i];
		
		//if you haven't visited
		if (visited[x] == 0){
			//then it would be the next parent of upcoming nodes
			parent[x] = start;
			dfs(x);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	int input1, input2;
	for (int i = 0; i < N-1; i++){
		cin >> input1 >> input2;
		
		v[input1].push_back(input2);
		v[input2].push_back(input1);
	}

	//start from root node 1
	dfs(1);
	
	//since root is 1, start from 2
	for  (int i = 2; i <= N; i++){
		cout << parent[i] << "\n";
	}
	
}

