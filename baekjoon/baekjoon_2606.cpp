#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const int N = 150;
int status[N];
int count = 0;
std::vector<int> v[N];

//bfs : not using recursion, so void rturn
std::queue<int> q;

void bfs(int start){
	q.push(start);
	status[start] = true;
	
	while(!q.empty()){
		//take front one (FIFO) out everytime (b/c BFS)
		int x = q.front();
		//std::cout << x << " ";
		q.pop();
		
		//iterate through all nodes
		for (int i = 0; i < v[x].size(); i++){
			//access each element that has connection with x
			int y = v[x][i];
			
			//if hasn't visited yet
			if (!status[y]){
				q.push(y);
				status[y] = true;
				count++;
			}
			
		}
		
	}	
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int num, c;
	//# of computers
	std::cin >> num;	
	//pair of connections
	std::cin >> c;
	
	int input1, input2;
	for (int i = 0; i < c; i++){
		std::cin >> input1 >> input2;
		v[input1].push_back(input2);
		v[input2].push_back(input1);
	}
	
	bfs(1);
	
	std::cout << count;
}














