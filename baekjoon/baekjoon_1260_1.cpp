#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

//a : number of vertices
//b : number of edges
//start : place to start
int a, b, start;
int input1, input2;

//dfs
const int N = 1001;
std::vector<int> v[N];
int visited[N];

void DFS(int x){
	visited[x] = 1;
	std::cout << x << " ";
	
	for (int i = 0; i < v[x].size(); i++){
		//getting each element that is connected to x
		int nv = v[x][i];
		
		//if hasn't visited
		if (!visited[nv]){
			visited[nv] = 1;
			DFS(nv);
			
		}	
	}
}

//bfs
std::queue<int> q;

void BFS(int start){
	q.push(start); 
	visited[start] = 1;

	//when it's not empty
	while(!q.empty()){
		//get the front elemeent and check it's connections w/ other nodes
		int x = q.front();
		std::cout << x << " ";
		q.pop();
		
		for (int i = 0; i < v[x].size(); i++){
			
			//each element of node is y (connected element)
			int y = v[x][i];
			//if hasn't visited
			if (!visited[y]){
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}


int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
	
	std::cin >> a >> b >> start;
	
	std::vector<std::pair <int, int>> inputs;
	
	for (int i = 0; i < b; i++){
		std::cin >> input1 >> input2;
		
        inputs.push_back(std::make_pair(input1, input2));	//put inputs in pair manner

	}
	
    std::sort(inputs.begin(), inputs.end());

	for (int i = 0; i < b; i++){
		
		v[inputs[i].first].push_back(inputs[i].second);
		v[inputs[i].second].push_back(inputs[i].first);
	}
	
	//for DFS:
	DFS(start);
	std::cout << "\n";
	std::fill_n(visited, 1001, 0);
	
	//for BFS:	
	BFS(start);
	
}














