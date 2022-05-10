#include <iostream>
#include <string>

using namespace std;

//N : number of elements, M : number of connections
int N, M;
int u,v;
int arr[1001][1001];
int visited[1001];
int count = 0;

void dfs(int x){
	
	//mark as visited
	visited[x] = 1;
	
	for (int i = 1; i <= N; i++){
		//if arr[x][i] <- connection exists, and
		//haven't visited,
		if (arr[x][i] && !visited[i]){
			dfs(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 1; i <= M; i++){
    	cin >> u >> v;
    	//in both direction ,so
    	arr[u][v] = 1;
    	arr[v][u] = 1;
	}
    
    //Node 1 through N, so
    for (int i = 1; i <= N; i++){
    	if (!visited[i]){
    		count++;
    		dfs(i);
		}
	}	
	
	cout << count;
}










