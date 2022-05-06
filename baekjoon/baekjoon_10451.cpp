#include<iostream>
#include <vector>

#define MAX 1001

using namespace std;

int N, M;
vector<int> v[1001];
bool visited[1001];

void DFS(int node) {
	visited[node]=true;
	
	for (int i=0; i< v[node].size(); i++) {
		int next = v[node][i];
		
		//if next hasn't visited
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   	cin >> N;
   
	while(N--){
		cin >> M;
		
		for (int i=1; i<=M; i++) {
			v[i].clear();
			visited[i]=false;
		}
		
		for (int i = 1; i <= M; i++){
			int input;
			cin >> input;
			v[i].push_back(input);
		}
		
		int count = 0;
		for (int i = 1; i <= M; i++){
			if (!visited[i]){
				DFS(i);
				count++;
			}
		}
		cout << count << "\n";
	}	
   
    return 0;
}














