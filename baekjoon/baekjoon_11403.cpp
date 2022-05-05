#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100;
int graph[MAX][MAX];
int N;

//use floyd - warshall algorithm
void floyd(void){
	
	
	for (int k = 0; k < N; k++){
		//x
		for (int i = 0; i < N; i++){
			//y
			for (int j = 0; j < N; j++){
				//if this is true (ex. both 1,2 and 2,3 are 1 (connection between 1 to 2 and 2 to 3) then we can say that 1 -> 3)
				if (graph[i][k] && graph[k][j])
					//and we denote connection as '1'
					graph[i][j] = 1;
			}
		}
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> graph[i][j];	
		}
	}
	
	floyd();

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) 
			cout << graph[i][j] << " ";	
		
		cout << endl;
	}
	
}





