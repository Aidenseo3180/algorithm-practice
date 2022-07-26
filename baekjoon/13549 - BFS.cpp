//https://jdselectron.tistory.com/58

#include <iostream>
#include <deque>

#define endl "\n"
#define MAX_SIZE 100000 + 1

using namespace std;

int N, K;	//start, destination
int visited[MAX_SIZE];	//works as both visited & counter

int BFS(){	//can be also solved using priority_queue
	deque<int> dq;
	dq.push_back(N);
	visited[N] = 1;
	
	while(!dq.empty()){
		
		//take elements out from front first
		int x = dq.front();
		dq.pop_front();	
		
		if (x == K) return visited[x] - 1;
		
		//must be the first if statement b/c we're looking for shortest
		//check for visited to prevent overlaps
		if (x * 2 < MAX_SIZE && !visited[x * 2]){
			dq.push_front(x * 2);	//push to front b/c we want to pop it & use it again as soon as possible (takes 0 sec, different than x - 1 & x + 1 where 1 sec passes)
			visited[x * 2] = visited[x];
		}
		
		if (x + 1 < MAX_SIZE && !visited[x + 1]){
			dq.push_back(x + 1);
			visited[x + 1] = visited[x] + 1;
		}
		
		if (x - 1 >= 0 && !visited[x - 1]){
			dq.push_back(x - 1);
			visited[x - 1] = visited[x] + 1;
		}
	}
}

int main(){
   	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	cout << BFS();


	return 0;
}


